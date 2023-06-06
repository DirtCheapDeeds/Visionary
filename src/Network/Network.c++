#include "./Main.h"

Network::Network(int num_inputs, int num_outputs) {
    input_layer = new Layer(num_inputs, nullptr, nullptr);
    output_layer = new Layer(num_outputs, nullptr, nullptr);

    input_layer->connect_layer(nullptr, output_layer);
    output_layer->connect_layer(input_layer, nullptr);

    layers.push_back(input_layer);
    layers.push_back(output_layer);

    cost = 0.0;
}

void Network::add_hidden_layer(int num_nodes) {
    Layer* layer = new Layer(num_nodes, output_layer->prev_layer, output_layer);

    layer->connect_layer(output_layer->prev_layer, output_layer);
    output_layer->prev_layer->connect_layer(output_layer->prev_layer->prev_layer, layer);
    output_layer->connect_layer(layer, output_layer->next_layer);

    layers.back() = layer;
    layers.push_back(output_layer);
}

std::vector<double> Network::run(DataPoint& data) {
    if (data.inputs.size() != input_layer->nodes.size()) throw "input size mismatch";
    if (data.expected_outputs.size() != output_layer->nodes.size()) throw "input size mismatch";

    for (int i = 0; i < (int) input_layer->nodes.size(); i++) {
        input_layer->nodes[i]->activation = data.inputs[i];
    }

    for (Layer* layer : layers) {
        layer->calculate_activations();
    }

    std::vector<double> outputs;

    cost = 0.0;

    for (Node* node : output_layer->nodes) {
        outputs.push_back(node->activation);
        cost += node->activation;
    }

    return outputs;
}

void Network::learn(std::vector<DataPoint*> training_data, double learn_rate) {
    for (DataPoint* data : training_data) {
        update_all_gradients(*data);
    }

    apply_all_gradients(learn_rate / training_data.size());

    reset_all_gradients();
}

double Network::average_cost(std::vector<DataPoint*> training_data) {
    double average_cost;
    for (DataPoint* data : training_data) {
        run(*data);
        average_cost += cost;
    }
    average_cost = average_cost / training_data.size();

    return average_cost;
}

void Network::apply_all_gradients(double learn_rate) {
    for (Layer* layer : layers) {
        layer->apply_gradients(learn_rate);
    }
}

void Network::update_all_gradients(DataPoint& data) {
    run(data);

    output_layer->calculate_output_layer_node_values(data);
    output_layer->update_gradients();

    for (int i = (int) layers.size() - 2; i >= 0; i--) {
        Layer* layer = layers[i];
        layer->calculate_node_values();
        layer->update_gradients();
    }
}

void Network::reset_all_gradients() {
    for (Layer* layer : layers) {
        layer->reset_gradients();
    }
}
