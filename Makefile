#http://www.gnu.org/software/make/manual/html_node/Automatic-Variables.html
#CC:= gcc-5
SOURCES:= $(wildcard src/*.c)
OBJECTS:= $(addprefix obj/,$(notdir $(SOURCES:.c=.o)))

CFLAGS:= -c -Wall -Werror -g -I/usr/local/include/SDL2 -Iinclude
LDFLAGS:= -L/usr/local/lib
LDLIBS:= -lSDL2 -lSDL2_image

EXECUTABLE:= deviant

# Instantly runs the game after linking
run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@echo "\nLinking...\n"
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^
	@echo "\nLinking for target $(EXECUTABLE) succeeded!\n\n"

obj/%.o: src/%.c
	@echo "\nCompiling:"
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	-rm $(OBJECTS) $(EXECUTABLE)
