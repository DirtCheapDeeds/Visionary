#include "Main.h"

int main() {
    
    std::srand(std::time(nullptr));

    initscr();
    noecho();
    init_colors();

    Network network(5, 3);
    network.add_hidden_layer(8);
    network.add_hidden_layer(8);

    std::string input;

    bool exit = false;
    while (!exit) {
        move(0, 0);
        clrtoeol();
        printw("Input: ");
        echo();
        char chars[100];
        getstr(chars);
        input = chars;
        noecho();
        refresh();

        display_network(network, 0, 2);

        if (false) {
            
        } else if (input == "quit") {
            exit = true;
        }
    }    

    endwin();

    return 0;
}
