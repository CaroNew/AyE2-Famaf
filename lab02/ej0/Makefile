CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g
DEPLOYFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -DNDEBUG
SOURCES = abb.c main.c
OBJECTS = $(SOURCES:.c=.o)
TESTOBJECTS = test.o $(filter-out main.o,$(OBJECTS))
TARGET = readtree



all: $(TARGET)


$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

test: $(TESTOBJECTS)
	-$(CC) $(CFLAGS) -o test $(TESTOBJECTS) $(LFLAGS) $(LIBS)
	-./test
	# gdb --nh test

.PHONY: deploy
deploy:
	$(CC) $(DEPLOYFLAGS) -o $(TARGET) $(SOURCES) $(LFLAGS) $(LIBS)

.PHONY: clean
clean:
	$(RM) $(OBJECTS) $(TESTOBJECTS) $(TARGET) test
