CC=g++
CFLAGS=-c -Wall
LDFLAGS=-lcryptopp
SOURCES=main.cpp encryption.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=encryption

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
