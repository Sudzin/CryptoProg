.PHONY: all clean

CXX = g++


CXXFLAGS = -Wall -lcrypto++


TARGET = cipher


SOURCES = main.cpp


OBJECTS = $(SOURCES:.cpp=.o)



all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CXXFLAGS) -o $(TARGET) 

clean:
	rm -f $(OBJECTS) $(TARGET)
