# Compiler and flags
CC := g++
CFLAGS := -std=c++11 -g
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files and executable name
SRCS := *.cpp Argumentator.hpp
EXECUTABLE := my_sfml_project

build: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXECUTABLE) $(SFML_LIBS)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
