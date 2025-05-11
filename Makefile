CXX = g++
CXXFLAGS = -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

all: app

app: main.o
\t$(CXX) $^ -o $@ $(LDFLAGS)

main.o: main.cpp
\t$(CXX) -c $(CXXFLAGS) $< -o $@

run: app
\t./app

clean:
\trm -f *.o app



