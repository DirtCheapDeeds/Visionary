#include "Main.h"

Edge::Edge() {
    first_node = nullptr;
    second_node = nullptr;
    weight = random;
}

Edge::Edge(Node* first_node, Node* second_node) 
    : first_node(first_node), second_node(second_node) {
    weight = random;
    first_node->output_edges.push_back(this);
    second_node->input_edges.push_back(this);
}