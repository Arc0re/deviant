#include "core.h"
#include "characters.h"

CHAR_DATA get_ascii(CHARS c)
{
    CHAR_DATA chr;
    chr.char_x = c % 16; chr.char_x = chr.char_x * TILE_WIDTH;
    chr.char_y = c / 16; chr.char_y = chr.char_y * TILE_HEIGHT;
    return chr;
}
