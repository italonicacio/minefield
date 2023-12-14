CXX = g++

CXXFLAGS = -g3 -O0 -Wall -Werror -std=c++11

LDLIBS = 

OBJ = main.o minefield.o keyboard.o

EXECUTABLE = minefield

$(EXECUTABLE): $(OBJ)
	$(CXX) -o $(EXECUTABLE) $(LDLIBS)

main.o: src/main.cpp
	$(CXX) -c $(CXXFLAGS) src/main.cpp

minefield.o: src/minefield.cpp
	$(CXX) -c $(CXXFLAGS) src/minefield.cpp

keyboard.o: src/keyboard.cpp
	$(CXX) -c $(CXXFLAGS) src/keyboard.cpp


.PHONY: clean run

clean: 
	rm *.o $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)