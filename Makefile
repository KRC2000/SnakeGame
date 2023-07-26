# Compiler and flags
CC := g++
CFLAGS := -std=c++11
SFML_LIBS := -lsfml-graphics -lsfml-window -lsfml-system

# Source files and executable name
SRCS := main.cpp Level.cpp
EXECUTABLE := my_sfml_project

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(EXECUTABLE) $(SFML_LIBS)

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)
