#include "Main.h"
#include "Data/Data.h"

int main() {
    
    std::srand(std::time(nullptr));

    if (false) {

        Network network(2, 2);
        network.add_hidden_layer(8);

        std::vector<DataPoint*>* data = custom_parse("training.txt");
        if ((int) data->size() == 0) printw("faliure");
        network.learn(*data, 0.5);

        return 0;
    }

    initscr();
    noecho();
    init_colors();

    //custom_fill("training.txt", 1000);
    //custom_fill("testing.txt", 100);

    Network network(2, 2);
    network.add_hidden_layer(8);

    std::string input;

    bool exit = false;
    move(0, 0);
    printw("Input: ");
    display_network(network, 0, 2);
    refresh();
    while (!exit) {
        input = prompt("command");

        display_network(network, 0, 2);
        
        if (input == "new") {
            
        } else if (input == "load") {
            
        } else if (input == "train") {
            train(network);
        } else if (input == "test") {
            test(network);
        } else if (input == "quit") {
            exit = true;
        }
    }    

    endwin();

    return 0;
}
