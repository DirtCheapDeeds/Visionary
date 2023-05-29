#include "Main.h"

Network::Network(int num_inputs, int num_outputs) {
    input_layer = new Layer(num_inputs, nullptr, nullptr);
    output_layer = new Layer(num_outputs, nullptr, nullptr);

    input_layer->connect_layer(nullptr, output_layer);
    output_layer->connect_layer(input_layer, nullptr);
}

void Network::add_hidden_layer(int num_nodes) {
    Layer* layer = new Layer(num_nodes, output_layer->prev_layer, output_layer);

    layer->connect_layer(output_layer->prev_layer, output_layer);
    output_layer->prev_layer->connect_layer(output_layer->prev_layer->prev_layer, layer);
    output_layer->connect_layer(layer, output_layer->next_layer);
}

std::vector<double> Network::run(std::vector<double> inputs) {
    if (inputs.size() != input_layer->nodes.size()) return;

    for (Node* node : input_layer->nodes) {
        node->activiation = inputs.back();
        inputs.pop_back();
    }

    for (Layer* layer : layers) {
        layer->calculate_activation();
    }

    output_layer->calculate_activation();
    std::vector<double> outputs;
    
    for (Node* node : output_layer->nodes) {
        outputs.push_back(node->activiation);
    }

    return outputs;
}