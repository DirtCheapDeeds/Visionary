#include "Main.h"

int main() {
    
    std::srand(std::time(nullptr));

    // initscr();
    // noecho();

    Network network(2, 2);

    endwin();

    return 0;
}
