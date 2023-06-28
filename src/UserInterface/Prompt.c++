#include "./Main.h"
#include "./Data/Data.h"

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
    if ((int) data->size() == 0) printw("faliure");
    network.learn(*data, learn_rate);
    display_network(network, 0, 2);
}

void test(Network& network) {
    std::string input = prompt("file");

    std::vector<DataPoint*>* data = custom_parse(input);
    if ((int) data->size() == 0) printw("faliure");

    int num_correct = 0;
    for (DataPoint* data_point: *data) {
        if (network.run(*data_point)[0] > network.run(*data_point)[1]) num_correct++;
    }
    move(1, 0);
    printw("%d percent", num_correct / (int) data->size() * 100);
    display_network(network, 0, 2);

}