#include "render.h"
#include "parser.h"
#include "core.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Spritesheet parsing, I know its awful, he he he */
/* EDIT ******* NOT USED ANYMORE, SEE character.h AND get_ascii() */
CHAR_DATA parse(const char* c)
{
    CHAR_DATA chars;
    int char_x = 0;
    int char_y = 0;

    int X = TILE_WIDTH;
    int Y = TILE_HEIGHT;

    /* 1ST LINE */
    if (strcmp(c, " ") == 0) {
        char_x = 0; char_y = 0;
    } else if (strcmp(c, "smile1") == 0) {
        char_x = X; char_y = 0;
    } else if (strcmp(c, "smile2") == 0) {
        char_x = X*2; char_y = 0;
    } else if (strcmp(c, "heart") == 0) {
        char_x = X*3; char_y = 0;
    } else if (strcmp(c, "diamond") == 0) {
        char_x = X*4; char_y = 0;
    } else if (strcmp(c, "club") == 0) {
        char_x = X*5; char_y = 0;
    } else if (strcmp(c, "spade") == 0) {
        char_x = X*6; char_y = 0;
    } else if (strcmp(c, "ball1") == 0) {
        char_x = X*7; char_y = 0;
    } else if (strcmp(c, "ball2") == 0) {
        char_x = X*8; char_y = 0;
    } else if (strcmp(c, "ball3") == 0) {
        char_x = X*9; char_y = 0;
    } else if (strcmp(c, "ball4") == 0) {
        char_x = X*10; char_y = 0;
    } else if (strcmp(c, "male") == 0) {
        char_x = X*11; char_y = 0;
    } else if (strcmp(c, "female") == 0) {
        char_x = X*12; char_y = 0;
    } else if (strcmp(c, "music1") == 0) {
        char_x = X*13; char_y = 0;
    } else if (strcmp(c, "music2") == 0) {
        char_x = X*14; char_y = 0;
    } else if (strcmp(c, "spark") == 0) {
        char_x = X*15; char_y = 0;
    /* 2ND LINE */
    } else if (strcmp(c, "right_thick_arrow") == 0) {
        char_x = 0; char_y = Y;
    } else if (strcmp(c, "left_thick_arrow") == 0) {
        char_x = X; char_y = Y;
    } else if (strcmp(c, "updown_arrow") == 0) {
        char_x = X*2; char_y = Y;
    } else if (strcmp(c, "!!") == 0) {
        char_x = X*3; char_y = Y;
    } else if (strcmp(c, "weird_p") == 0) {
        char_x = X*4; char_y = Y;
    } else if (strcmp(c, "paragraph") == 0) {
        char_x = X*5; char_y = Y;
    } else if (strcmp(c, "small_half_block") == 0) {
        char_x = X*6; char_y = Y;
    } else if (strcmp(c, "updown_arrow2") == 0) {
        char_x = X*7; char_y = Y;
    } else if (strcmp(c, "up_arrow") == 0) {
        char_x = X*8; char_y = Y;
    } else if (strcmp(c, "down_arrow") == 0) {
        char_x = X*9; char_y = Y;
    } else if (strcmp(c, "right_arrow") == 0) {
        char_x = X*10; char_y = Y;
    } else if (strcmp(c, "left_arrow") == 0) {
        char_x = X*11; char_y = Y;
    } else if (strcmp(c, "bottom_left_angle") == 0) {
        char_x = X*12; char_y = Y;
    } else if (strcmp(c, "left_right_arrow") == 0) {
        char_x = X*13; char_y = Y;
    } else if (strcmp(c, "up_thick_arrow") == 0) {
        char_x = X*14; char_y = Y;
    } else if (strcmp(c, "down_thick_arrow") == 0) {
        char_x = X*15; char_y = Y;
    /* 3RD LINE */
    } else if (strcmp(c, " ") == 0) {
        char_x = 0; char_y = Y;
    } else if (strcmp(c, "!") == 0) {
        char_x = X; char_y = Y*2;
    } else if (strcmp(c, "\"") == 0) {
        char_x = X*2; char_y = Y*2;
    } else if (strcmp(c, "#") == 0) {
        char_x = X*3; char_y = Y*2;
    } else if (strcmp(c, "$") == 0) {
        char_x = X*4; char_y = Y*2;
    } else if (strcmp(c, "%") == 0) {
        char_x = X*5; char_y = Y*2;
    } else if (strcmp(c, "&") == 0) {
        char_x = X*6; char_y = Y*2;
    } else if (strcmp(c, "'") == 0) {
        char_x = X*7; char_y = Y*2;
    } else if (strcmp(c, "(") == 0) {
        char_x = X*8; char_y = Y*2;
    } else if (strcmp(c, ")") == 0) {
        char_x = X*9; char_y = Y*2;
    } else if (strcmp(c, "*") == 0) {
        char_x = X*10; char_y = Y*2;
    } else if (strcmp(c, "+") == 0) {
        char_x = X*11; char_y = Y*2;
    } else if (strcmp(c, ",") == 0) {
        char_x = X*12; char_y = Y*2;
    } else if (strcmp(c, "-") == 0) {
        char_x = X*13; char_y = Y*2;
    } else if (strcmp(c, ".") == 0) {
        char_x = X*14; char_y = Y*2;
    } else if (strcmp(c, "/") == 0) {
        char_x = X*15; char_y = Y*2;
    /* 4TH LINE */
    } else if (strcmp(c, "0") == 0) {
        char_x = 0; char_y = Y*3;
    } else if (strcmp(c, "1") == 0) {
        char_x = X; char_y = Y*3;
    } else if (strcmp(c, "2") == 0) {
        char_x = X*2; char_y = Y*3;
    } else if (strcmp(c, "3") == 0) {
        char_x = X*3; char_y = Y*3;
    } else if (strcmp(c, "4") == 0) {
        char_x = X*4; char_y = Y*3;
    } else if (strcmp(c, "5") == 0) {
        char_x = X*5; char_y = Y*3;
    } else if (strcmp(c, "6") == 0) {
        char_x = X*6; char_y = Y*3;
    } else if (strcmp(c, "7") == 0) {
        char_x = X*7; char_y = Y*3;
    } else if (strcmp(c, "8") == 0) {
        char_x = X*8; char_y = Y*3;
    } else if (strcmp(c, "9") == 0) {
        char_x = X*9; char_y = Y*3;
    } else if (strcmp(c, ":") == 0) {
        char_x = X*10; char_y = Y*3;
    } else if (strcmp(c, ";") == 0) {
        char_x = X*11; char_y = Y*3;
    } else if (strcmp(c, "<") == 0) {
        char_x = X*12; char_y = Y*3;
    } else if (strcmp(c, "=") == 0) {
        char_x = X*13; char_y = Y*3;
    } else if (strcmp(c, ">") == 0) {
        char_x = X*14; char_y = Y*3;
    } else if (strcmp(c, "?") == 0) {
        char_x = X*15; char_y = Y*3;
    /* 5TH LINE */
    } else if (strcmp(c, "@") == 0) { // THE GREATER ONE
        char_x = 0; char_y = Y*4;
    } else if (strcmp(c, "A") == 0) {
        char_x = X; char_y = Y*4;
    } else if (strcmp(c, "B") == 0) {
        char_x = X*2; char_y = Y*4;
    } else if (strcmp(c, "C") == 0) {
        char_x = X*3; char_y = Y*4;
    } else if (strcmp(c, "D") == 0) {
        char_x = X*4; char_y = Y*4;
    } else if (strcmp(c, "E") == 0) {
        char_x = X*5; char_y = Y*4;
    } else if (strcmp(c, "F") == 0) {
        char_x = X*6; char_y = Y*4;
    } else if (strcmp(c, "G") == 0) {
        char_x = X*7; char_y = Y*4;
    } else if (strcmp(c, "H") == 0) {
        char_x = X*8; char_y = Y*4;
    } else if (strcmp(c, "I") == 0) {
        char_x = X*9; char_y = Y*4;
    } else if (strcmp(c, "J") == 0) {
        char_x = X*10; char_y = Y*4;
    } else if (strcmp(c, "K") == 0) {
        char_x = X*11; char_y = Y*4;
    } else if (strcmp(c, "L") == 0) {
        char_x = X*12; char_y = Y*4;
    } else if (strcmp(c, "M") == 0) {
        char_x = X*13; char_y = Y*4;
    } else if (strcmp(c, "N") == 0) {
        char_x = X*14; char_y = Y*4;
    } else if (strcmp(c, "O") == 0) {
        char_x = X*15; char_y = Y*4;
    /* 6TH LINE */
    } else if (strcmp(c, "P") == 0) {
        char_x = 0; char_y = Y*5;
    } else if (strcmp(c, "Q") == 0) {
        char_x = X; char_y = Y*5;
    } else if (strcmp(c, "R") == 0) {
        char_x = X*2; char_y = Y*5;
    } else if (strcmp(c, "S") == 0) {
        char_x = X*3; char_y = Y*5;
    } else if (strcmp(c, "T") == 0) {
        char_x = X*4; char_y = Y*5;
    } else if (strcmp(c, "U") == 0) {
        char_x = X*5; char_y = Y*5;
    } else if (strcmp(c, "V") == 0) {
        char_x = X*6; char_y = Y*5;
    } else if (strcmp(c, "W") == 0) {
        char_x = X*7; char_y = Y*5;
    } else if (strcmp(c, "X") == 0) {
        char_x = X*8; char_y = Y*5;
    } else if (strcmp(c, "Y") == 0) {
        char_x = X*9; char_y = Y*5;
    } else if (strcmp(c, "Z") == 0) {
        char_x = X*10; char_y = Y*5;
    } else if (strcmp(c, "[") == 0) {
        char_x = X*11; char_y = Y*5;
    } else if (strcmp(c, "\\") == 0) {
        char_x = X*12; char_y = Y*5;
    } else if (strcmp(c, "]") == 0) {
        char_x = X*13; char_y = Y*5;
    } else if (strcmp(c, "^") == 0) {
        char_x = X*14; char_y = Y*5;
    } else if (strcmp(c, "_") == 0) {
        char_x = X*15; char_y = Y*5;
    /* 7TH LINE */
    } else if (strcmp(c, "single_quote") == 0) {
        char_x = 0; char_y = Y*6;
    } else if (strcmp(c, "a") == 0) {
        char_x = X; char_y = Y*6;
    } else if (strcmp(c, "b") == 0) {
        char_x = X*2; char_y = Y*6;
    } else if (strcmp(c, "c") == 0) {
        char_x = X*3; char_y = Y*6;
    } else if (strcmp(c, "d") == 0) {
        char_x = X*4; char_y = Y*6;
    } else if (strcmp(c, "e") == 0) {
        char_x = X*5; char_y = Y*6;
    } else if (strcmp(c, "f") == 0) {
        char_x = X*6; char_y = Y*6;
    } else if (strcmp(c, "g") == 0) {
        char_x = X*7; char_y = Y*6;
    } else if (strcmp(c, "h") == 0) {
        char_x = X*8; char_y = Y*6;
    } else if (strcmp(c, "i") == 0) {
        char_x = X*9; char_y = Y*6;
    } else if (strcmp(c, "j") == 0) {
        char_x = X*10; char_y = Y*6;
    } else if (strcmp(c, "k") == 0) {
        char_x = X*11; char_y = Y*6;
    } else if (strcmp(c, "l") == 0) {
        char_x = X*12; char_y = Y*6;
    } else if (strcmp(c, "m") == 0) {
        char_x = X*13; char_y = Y*6;
    } else if (strcmp(c, "n") == 0) {
        char_x = X*14; char_y = Y*6;
    } else if (strcmp(c, "o") == 0) {
        char_x = X*15; char_y = Y*6;
    /* YTH LINE */
    } else if (strcmp(c, "p") == 0) {
        char_x = 0; char_y = Y*7;
    } else if (strcmp(c, "q") == 0) {
        char_x = X; char_y = Y*7;
    } else if (strcmp(c, "r") == 0) {
        char_x = X*2; char_y = Y*7;
    } else if (strcmp(c, "s") == 0) {
        char_x = X*3; char_y = Y*7;
    } else if (strcmp(c, "t") == 0) {
        char_x = X*4; char_y = Y*7;
    } else if (strcmp(c, "u") == 0) {
        char_x = X*5; char_y = Y*7;
    } else if (strcmp(c, "v") == 0) {
        char_x = X*6; char_y = Y*7;
    } else if (strcmp(c, "w") == 0) {
        char_x = X*7; char_y = Y*7;
    } else if (strcmp(c, "x") == 0) {
        char_x = X*8; char_y = Y*7;
    } else if (strcmp(c, "y") == 0) {
        char_x = X*9; char_y = Y*7;
    } else if (strcmp(c, "z") == 0) {
        char_x = X*10; char_y = Y*7;
    } else if (strcmp(c, "{") == 0) {
        char_x = X*11; char_y = Y*7;
    } else if (strcmp(c, "thick_colon") == 0) {
        char_x = X*12; char_y = Y*7;
    } else if (strcmp(c, "}") == 0) {
        char_x = X*13; char_y = Y*7;
    } else if (strcmp(c, "~") == 0) {
        char_x = X*14; char_y = Y*7;
    } else if (strcmp(c, "delta") == 0) {
        char_x = X*15; char_y = Y*7;
    /* 9TH LINE */
    } else if (strcmp(c, "ç") == 0) {
        char_x = 0; char_y = Y*8;
    } else if (strcmp(c, "ü") == 0) {
        char_x = X; char_y = Y*8;
    } else if (strcmp(c, "é") == 0) {
        char_x = X*2; char_y = Y*8;
    } else if (strcmp(c, "â") == 0) {
        char_x = X*3; char_y = Y*8;
    } else if (strcmp(c, "ä") == 0) {
        char_x = X*4; char_y = Y*8;
    } else if (strcmp(c, "à") == 0) {
        char_x = X*5; char_y = Y*8;
    } else if (strcmp(c, "á") == 0) {
        char_x = X*6; char_y = Y*8;
    } else if (strcmp(c, "sigma") == 0) {
        char_x = X*7; char_y = Y*8;
    } else if (strcmp(c, "ê") == 0) {
        char_x = X*8; char_y = Y*8;
    } else if (strcmp(c, "ë") == 0) {
        char_x = X*9; char_y = Y*8;
    } else if (strcmp(c, "è") == 0) {
        char_x = X*10; char_y = Y*8;
    } else if (strcmp(c, "ï") == 0) {
        char_x = X*11; char_y = Y*8;
    } else if (strcmp(c, "î") == 0) {
        char_x = X*12; char_y = Y*8;
    } else if (strcmp(c, "ì") == 0) {
        char_x = X*13; char_y = Y*8;
    } else if (strcmp(c, "Ä") == 0) {
        char_x = X*14; char_y = Y*8;
    } else if (strcmp(c, "dot_a") == 0) {
        char_x = X*15; char_y = Y*8;
    /* 10TH LINE */
    } else if (strcmp(c, "È") == 0) {
        char_x = 0; char_y = Y*9;
    } else if (strcmp(c, "ae") == 0) {
        char_x = X; char_y = Y*9;
    } else if (strcmp(c, "weird_A") == 0) {
        char_x = X*2; char_y = Y*9;
    } else if (strcmp(c, "ô") == 0) {
        char_x = X*3; char_y = Y*9;
    } else if (strcmp(c, "ö") == 0) {
        char_x = X*4; char_y = Y*9;
    } else if (strcmp(c, "ò") == 0) {
        char_x = X*5; char_y = Y*9;
    } else if (strcmp(c, "û") == 0) {
        char_x = X*6; char_y = Y*9;
    } else if (strcmp(c, "ù") == 0) {
        char_x = X*7; char_y = Y*9;
    } else if (strcmp(c, "ÿ") == 0) {
        char_x = X*8; char_y = Y*9;
    } else if (strcmp(c, "Ö") == 0) {
        char_x = X*9; char_y = Y*9;
    } else if (strcmp(c, "Ü") == 0) {
        char_x = X*10; char_y = Y*9;
    } else if (strcmp(c, "cents") == 0) {
        char_x = X*11; char_y = Y*9;
    } else if (strcmp(c, "pounds") == 0) {
        char_x = X*12; char_y = Y*9;
    } else if (strcmp(c, "yen") == 0) {
        char_x = X*13; char_y = Y*9;
    } else if (strcmp(c, "Pt") == 0) {
        char_x = X*14; char_y = Y*9;
    } else if (strcmp(c, "sea_horse") == 0) {
        char_x = X*15; char_y = Y*9;
    /* 11TH LINE */
    } else if (strcmp(c, "ā") == 0) {
        char_x = 0; char_y = Y*10;
    } else if (strcmp(c, "ī") == 0) {
        char_x = X; char_y = Y*10;
    } else if (strcmp(c, "ō") == 0) {
        char_x = X*2; char_y = Y*10;
    } else if (strcmp(c, "ū") == 0) {
        char_x = X*3; char_y = Y*10;
    } else if (strcmp(c, "ñ") == 0) {
        char_x = X*4; char_y = Y*10;
    } else if (strcmp(c, "Ñ") == 0) {
        char_x = X*5; char_y = Y*10;
    } else if (strcmp(c, "_a") == 0) {
        char_x = X*6; char_y = Y*10;
    } else if (strcmp(c, "_o") == 0) {
        char_x = X*7; char_y = Y*10;
    } else if (strcmp(c, "inverted_?") == 0) {
        char_x = X*8; char_y = Y*10;
    } else if (strcmp(c, "top_left_angle") == 0) {
        char_x = X*9; char_y = Y*10;
    } else if (strcmp(c, "top_right_angle") == 0) {
        char_x = X*10; char_y = Y*10;
    } else if (strcmp(c, "zig1") == 0) {
        char_x = X*11; char_y = Y*10;
    } else if (strcmp(c, "zig2") == 0) {
        char_x = X*12; char_y = Y*10;
    } else if (strcmp(c, "big_;") == 0) {
        char_x = X*13; char_y = Y*10;
    } else if (strcmp(c, "<<") == 0) {
        char_x = X*14; char_y = Y*10;
    } else if (strcmp(c, ">>") == 0) {
        char_x = X*15; char_y = Y*10;
    /* 12TH LINE */
    } else if (strcmp(c, "spaced_dots") == 0) {
        char_x = 0; char_y = Y*11;
    } else if (strcmp(c, "dots") == 0) {
        char_x = X; char_y = Y*11;
    } else if (strcmp(c, "inverted_dots") == 0) {
        char_x = X*2; char_y = Y*11;
    } else if (strcmp(c, "pipe") == 0) {
        char_x = X*3; char_y = Y*11;
    } else if (strcmp(c, "pipe2") == 0) {
        char_x = X*4; char_y = Y*11;
    } else if (strcmp(c, "pipe3") == 0) {
        char_x = X*5; char_y = Y*11;
    } else if (strcmp(c, "d_pipe") == 0) {
        char_x = X*6; char_y = Y*11;
    } else if (strcmp(c, "d_pipe2") == 0) {
        char_x = X*7; char_y = Y*11;
    } else if (strcmp(c, "inverted_F") == 0) {
        char_x = X*8; char_y = Y*11;
    } else if (strcmp(c, "-||") == 0) {
        char_x = X*9; char_y = Y*11;
    } else if (strcmp(c, "||") == 0) {
        char_x = X*10; char_y = Y*11;
    } else if (strcmp(c, "d_top_right_angle") == 0) {
        char_x = X*11; char_y = Y*11;
    } else if (strcmp(c, "d_bottom_right_angle") == 0) {
        char_x = X*12; char_y = Y*11;
    } else if (strcmp(c, "other_bottom_right_angle") == 0) {
        char_x = X*13; char_y = Y*11;
    } else if (strcmp(c, "inverted_inverted_F") == 0) {
        char_x = X*14; char_y = Y*11;
    } else if (strcmp(c, "worm") == 0) {
        char_x = X*15; char_y = Y*11;
    /* 13TH LINE, names lose all meaning */
    } else if (strcmp(c, "bottom_left_angle") == 0) {
        char_x = 0; char_y = Y*12;
    } else if (strcmp(c, "bottom_right_angle") == 0) {
        char_x = X; char_y = Y*12;
    } else if (strcmp(c, "--") == 0) {
        char_x = X*2; char_y = Y*12;
    } else if (strcmp(c, "half_cross") == 0) {
        char_x = X*3; char_y = Y*12;
    } else if (strcmp(c, "straight_long") == 0) {
        char_x = X*4; char_y = Y*12;
    } else if (strcmp(c, "cross") == 0) {
        char_x = X*5; char_y = Y*12;
    } else if (strcmp(c, "double_F") == 0) {
        char_x = X*6; char_y = Y*12;
    } else if (strcmp(c, "thick||") == 0) {
        char_x = X*7; char_y = Y*12;
    } else if (strcmp(c, "d_bottom_left_angle") == 0) {
        char_x = X*8; char_y = Y*12;
    } else if (strcmp(c, "d_top_left_angle") == 0) {
        char_x = X*9; char_y = Y*12;
    } else if (strcmp(c, "road1") == 0) {
        char_x = X*10; char_y = Y*12;
    } else if (strcmp(c, "road2") == 0) {
        char_x = X*11; char_y = Y*12;
    } else if (strcmp(c, "road3") == 0) {
        char_x = X*12; char_y = Y*12;
    } else if (strcmp(c, "road4") == 0) {
        char_x = X*13; char_y = Y*12;
    } else if (strcmp(c, "road5") == 0) {
        char_x = X*14; char_y = Y*12;
    } else if (strcmp(c, "road6") == 0) {
        char_x = X*15; char_y = Y*12;
    /* 14TH LINE */
    } else if (strcmp(c, "square_U") == 0) {
        char_x = 0; char_y = Y*13;
    } else if (strcmp(c, "T_with_hat") == 0) {
        char_x = X; char_y = Y*13;
    } else if (strcmp(c, "fake_pi") == 0) {
        char_x = X*2; char_y = Y*13;
    } else if (strcmp(c, "inverted_fake_pi") == 0) {
        char_x = X*3; char_y = Y*13;
    } else if (strcmp(c, "inverted_small_f") == 0) {
        char_x = X*4; char_y = Y*13;
    } else if (strcmp(c, "small_f") == 0) {
        char_x = X*5; char_y = Y*13;
    } else if (strcmp(c, "falled_f") == 0) {
        char_x = X*6; char_y = Y*13;
    } else if (strcmp(c, "big_H") == 0) {
        char_x = X*7; char_y = Y*13;
    } else if (strcmp(c, "croix_lorraine") == 0) {
        char_x = X*8; char_y = Y*13;
    } else if (strcmp(c, "small_br_angle") == 0) {
        char_x = X*9; char_y = Y*13;
    } else if (strcmp(c, "small_tl_angle") == 0) {
        char_x = X*10; char_y = Y*13;
    } else if (strcmp(c, "[]") == 0) { // THERE
        char_x = X*11; char_y = Y*13;
    } else if (strcmp(c, "halfh_block") == 0) {
        char_x = X*12; char_y = Y*13;
    } else if (strcmp(c, "vertl_half_block") == 0) {
        char_x = X*13; char_y = Y*13;
    } else if (strcmp(c, "vertd_half_block") == 0) {
        char_x = X*14; char_y = Y*13;
    } else if (strcmp(c, "halfv_half_block") == 0) {
        char_x = X*15; char_y = Y*13;
    /* 15TH LINE */
    } else if (strcmp(c, "alpha") == 0) {
        char_x = 0; char_y = Y*14;
    } else if (strcmp(c, "beta") == 0) {
        char_x = X; char_y = Y*14;
    } else if (strcmp(c, "gamma") == 0) {
        char_x = X*2; char_y = Y*14;
    } else if (strcmp(c, "pi") == 0) {
        char_x = X*3; char_y = Y*14;
    } else if (strcmp(c, "epsilon") == 0) {
        char_x = X*4; char_y = Y*14;
    } else if (strcmp(c, "sigma") == 0) {
        char_x = X*5; char_y = Y*14;
    } else if (strcmp(c, "micro") == 0) {
        char_x = X*6; char_y = Y*14;
    } else if (strcmp(c, "greek_Y") == 0) {
        char_x = X*7; char_y = Y*14;
    } else if (strcmp(c, "missigno") == 0) { // mmm
        char_x = X*8; char_y = Y*14;
    } else if (strcmp(c, "theta") == 0) {
        char_x = X*9; char_y = Y*14;
    } else if (strcmp(c, "omega") == 0) {
        char_x = X*10; char_y = Y*14;
    } else if (strcmp(c, "small_delta") == 0) {
        char_x = X*11; char_y = Y*14;
    } else if (strcmp(c, "laying_Y") == 0) {
        char_x = X*12; char_y = Y*14;
    } else if (strcmp(c, "laying_Y_2") == 0) {
        char_x = X*13; char_y = Y*14;
    } else if (strcmp(c, "belongs") == 0) {
        char_x = X*14; char_y = Y*14;
    } else if (strcmp(c, "nu") == 0) {
        char_x = X*15; char_y = Y*14;
    /* 16TH LINE */
    } else if (strcmp(c, "triple=") == 0) {
        char_x = 0; char_y = Y*15;
    } else if (strcmp(c, "+-") == 0) {
        char_x = X; char_y = Y*15;
    } else if (strcmp(c, ">_") == 0) {
        char_x = X*2; char_y = Y*15;
    } else if (strcmp(c, "<_") == 0) {
        char_x = X*3; char_y = Y*15;
    } else if (strcmp(c, "sugar_cane") == 0) {
        char_x = X*4; char_y = Y*15;
    } else if (strcmp(c, "big_J") == 0) {
        char_x = X*5; char_y = Y*15;
    } else if (strcmp(c, "divide") == 0) {
        char_x = X*6; char_y = Y*15;
    } else if (strcmp(c, "wave") == 0) {
        char_x = X*7; char_y = Y*15;
    } else if (strcmp(c, "small_o") == 0) { // mmm
        char_x = X*8; char_y = Y*15;
    } else if (strcmp(c, "floating_dot") == 0) {
        char_x = X*9; char_y = Y*15;
    } else if (strcmp(c, "floating_dot2") == 0) {
        char_x = X*10; char_y = Y*15;
    } else if (strcmp(c, "squareV") == 0) {
        char_x = X*11; char_y = Y*15;
    } else if (strcmp(c, "small_n") == 0) {
        char_x = X*12; char_y = Y*15;
    } else if (strcmp(c, "square_2") == 0) {
        char_x = X*13; char_y = Y*15;
    } else if (strcmp(c, "big_dot") == 0) {
        char_x = X*14; char_y = Y*15;
    } else if (strcmp(c, " ") == 0) {
        char_x = X*15; char_y = Y*15;
    } else {
        printf("Wrong string: %s\n", c);
    }

    chars.char_x = char_x;
    chars.char_y = char_y;
    return chars;
}
