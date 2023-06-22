#include "./Main.h"
#include "./DataParsing/DataParsing.h"

std::string prompt(std::string text) {
    move(0, 0);
    clrtoeol();
    printw("%s: ", text.c_str());
    echo();
    char chars[100];
    getstr(chars);
    std::string input = chars;
    noecho();
    refresh();
    return input;
}

void train(Network& network) {
    std::string input = prompt("file");
    double learn_rate = std::stod(prompt("learn_rate"));

    std::vector<DataPoint*>* data = custom_parse(input);
    network.learn(*data, learn_rate);
    display_network(network, 0, 2);
}

void test(Network& network) {
    std::string input = prompt("file");

}