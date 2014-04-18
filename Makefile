CC = gcc
CXXFLAGS = -Wall
LDFLAGS = -pthread
LIBS = -lcdk -lncurses

HEADERS = src/ui_helper.h
OBJECTS = src/main.o src/ui_helper.o

all: leafftp

leafftp: $(OBJECTS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

debug: CXXFLAGS += -g3 -DDEBUG
debug: leafftp

%.o: %.c $(HEADERS)
	$(CC) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

clean:
	rm -rf src/*.o
	rm -rf leafftp
