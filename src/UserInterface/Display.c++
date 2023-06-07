#include "./Main.h"

void display_network(Network& network, int x, int y) {
    for (int i = 0; i < (int) network.layers.size(); i++) {
        Layer* layer = network.layers[i];
        for (int j = 0; j < (int) layer->nodes.size(); j++) {
            Node* node = layer->nodes[j];

            move(y + j, x + 6*i);
            attron(COLOR_PAIR(activation_to_color(node->activation)));
            printw("O");
            attroff(COLOR_PAIR(activation_to_color(node->activation)));
            if (i != (int) network.layers.size() - 1 && j + 1 <= (int) network.layers[i+1]->nodes.size()) printw(" --- ");
        }
    }
    refresh();
}