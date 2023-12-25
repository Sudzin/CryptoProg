CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++11
LIBS = -lcryptopp
all: app
app: main.cpp
	$(CXX) $(CXXFLAGS) -o app main.cpp $(LIBS)
clean:
	rm -f app
