CXX:= g++-5
SOURCES:= $(wildcard src/*.cpp)
OBJECTS:= $(addprefix obj/,$(notdir $(SOURCES:.cpp=.o)))

CXXFLAGS:= -c -std=c++14 -Wall -Werror -g -I/usr/local/include/SDL2 -Iinclude
LDFLAGS:= -L/usr/local/lib
LDLIBS:= -lSDL2 -lSDL2_image

EXECUTABLE:= deviant

# Instantly runs the game after linking
run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo "\nLinking...\n"
	$(CXX) $(LDFLAGS) $(LDLIBS) -o $@ $^
	@echo "\nLinking for target $(EXECUTABLE) succeeded!\n\n"

obj/%.o: src/%.cpp
	@echo "\nCompiling:"
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	-rm $(OBJECTS) $(EXECUTABLE)
