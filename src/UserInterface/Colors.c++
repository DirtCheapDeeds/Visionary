#include "./Main.h"

void init_colors() {

    start_color();

    init_pair(white, COLOR_WHITE, COLOR_BLACK);
    
    init_pair(blue, COLOR_BLUE, COLOR_BLACK);
    init_pair(cyan, COLOR_CYAN, COLOR_BLACK);
    init_pair(green, COLOR_GREEN, COLOR_BLACK);
    init_pair(yellow, COLOR_YELLOW, COLOR_BLACK);
    init_pair(magenta, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(red, COLOR_RED, COLOR_BLACK);

}