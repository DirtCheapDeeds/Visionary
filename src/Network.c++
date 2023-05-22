#include "Main.h"

Network::Network(const ilist& layer_sizes, int num_layers) {
    for (int i = 0; i < layer_sizes.size() - 1; i++) {
        layers.push_back(new Layer(layer_sizes[i], layer_sizes[i + 1]));
    }
}

dlist& Network::calculate_outputs(dlist& inputs) {
    for (Layer* layer : layers) {
        inputs  = layer->calculate_outputs(inputs);
    }
    return inputs;
}

int Network::classify(dlist& inputs) {
    dlist& outputs = calculate_outputs(inputs);
    int max_index = 0;
    double max_num = outputs[0];
    for (int i = 0; i < outputs.size(); i++) {
        if (outputs[i] > max_num) {
            max_num = outputs[i];
            max_index = i;
        }
    }
    return max_index;
}

double Network::cost(dlist& inputs, dlist& expected_outputs) {
    dlist& outputs = calculate_outputs(inputs);
    Layer* output_layer = layers.back();
    double cost = 0;

    for (int output = 0; output < outputs.size(); output++) {
        cost += output_layer->node_cost(outputs[output], expected_outputs[output]);
    }
    return cost;
}

double Network::cost(ddlist& inputs, ddlist& expected_outputs) {
    double total_cost = 0;

    for (int i = 0; i < inputs.size(); i++) {
        total_cost += cost(inputs[i], expected_outputs[i]);
    }

    return total_cost / inputs.size();
}