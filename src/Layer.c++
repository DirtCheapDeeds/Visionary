#include "Main.h"

Layer::Layer(int num_nodes, Layer* prev_layer, Layer* next_layer) 
    : prev_layer(prev_layer), next_layer(next_layer) {

    for (int i = 0; i < num_nodes; i++) {
        nodes.push_back(new Node());
    }

    connect_layer(prev_layer, prev_layer);
}

void Layer::connect_layer(Layer* prev_layer, Layer* next_layer) {
    this->prev_layer = prev_layer;
    this->next_layer = next_layer;
    if (prev_layer != nullptr) {
        for (Node* first_node : prev_layer->nodes) {
            for (Node* second_node : this->nodes) {
                first_node->output_edges.clear();
                second_node->input_edges.clear();
                new Edge(first_node, second_node);
            }
        }
    }
    if (next_layer != nullptr) {
        for (Node* first_node : this->nodes) {
            for (Node* second_node : next_layer->nodes) {
                first_node->output_edges.clear();
                second_node->input_edges.clear();
                new Edge(first_node, second_node);
            }
        }
    }
}

void Layer::calculate_activation() {
    for (Node* node : nodes) {
        double weighted_sum = -node->bias;
        for (Edge* input : node->input_edges) {
            weighted_sum += input->weight * input->first_node->activiation;
        }
        node->activiation = activation_function(weighted_sum);
    }
}

double Layer::activation_function(double weighted_sum) {
    return 1 / (1 + exp(-weighted_sum));
}
    