MAJOR=0
MINOR=0
BUILD=$(shell cat version.build)
DEFINES=-DMAJOR=$(MAJOR) -DMINOR=$(MINOR) -D BUILD=$(BUILD)

all:
	gcc main.c aula04.c -o test $(DEFINES)
	echo $$(($(BUILD)+1)) > version.build

clean:
	rm test
