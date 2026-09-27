CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

render: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o render

run: render
	./render

clean:
	rm -f render *.ppm