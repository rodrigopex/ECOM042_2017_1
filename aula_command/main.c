#include <stdio.h>
#include <stdint.h>
#include <string.h>

/*
 - Help
 - Write
 - Read
 - Clean
*/

typedef enum {
    Ok,
    Fail,
    MemoryError
} Status;

typedef Status (*Function)();

typedef enum {
    Write,
    Read,
    Clean,
    Dump,
    Copy,
    NumberOfCommands
} __attribute__((__packed__)) Command;

typedef struct {
    char * stringCommand;
    Function receiver;
    char * help;
} CommandDescriptor;

void help(CommandDescriptor * cmdDesc) {
    printf("Help: \n");
    for(int i = 0; i < NumberOfCommands; printf("%s", cmdDesc[i].help), ++i);
}

Status write() {
    printf("Writing...[");
    return Ok;
}

Status read() {
    printf("Reading...[");
    return Fail;
}

Status clean() {
    printf("Cleaning...[");
    return Ok;
}

Status dump() {
    printf("Dumping...[");
    return Ok;
}

Status copy() {
    printf("Copying...[");
    return Fail;
}
//$ test Write --> Argc 2, Argv ["test", "Write"]
int main(int argc, char **argv) {
    CommandDescriptor invoker[NumberOfCommands] = {
        {"Write", &write, "$ test Write [CMD...]\n"},
        {"Read", &read, "$ test Read [CMD...]\n"},
        {"Clean", &clean, "$ test Clean [CMD...]\n"},
        {"Dump", &dump, "$ test Dump [CMD...]\n"},
        {"Copy", &copy, "$ test Copy [CMD...]\n"},
    };

    for(int i = 1; i < argc; ++i) {
        Command cmd;
        if(argc >= 2) {
            for(cmd = Write; cmd < NumberOfCommands; ++cmd) {
                if(strcmp(argv[i], invoker[cmd].stringCommand) == 0) {
                    break;
                }
            }
        }
        if(cmd == NumberOfCommands) {
            help(invoker);
        } else {
            Status test = (* invoker[cmd].receiver)();
            printf("%s\n", (test == Ok? "Ok]" : "Failed]"));
        }
    }
    return 0;
}
