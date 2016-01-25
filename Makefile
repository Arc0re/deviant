#http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
CXX:= g++-5
SOURCES:= $(wildcard src/*.cc)
OBJECTS:= $(addprefix obj/,$(notdir $(SOURCES:.cc=.o)))

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

obj/%.o: src/%.cc
	@echo "\nCompiling:"
	$(CXX) $(CXXFLAGS) -o $@ $<

.PHONY: clean
clean:
	-rm $(OBJECTS) $(EXECUTABLE)
