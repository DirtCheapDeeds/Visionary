#include "Main.h"
#include "DataParsing/DataParsing.h"

int main() {
    
    std::srand(std::time(nullptr));

    initscr();
    noecho();
    init_colors();

    custom_fill("training.txt", 1000);
    custom_fill("testing.txt", 100);

    Network network(2, 2);
    network.add_hidden_layer(8);

    std::string input;

    bool exit = false;
    move(0, 0);
    printw("Input: ");
    display_network(network, 0, 2);
    refresh();
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
