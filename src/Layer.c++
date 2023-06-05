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

void Layer::calculate_activations() {
    for (Node* node : nodes) {
        node->calcualte_weighted_sum();
        node->calculate_activation();
    } 
}

void Layer::calculate_node_values() {
    for (Node* node : nodes) {
        node->calculate_node_value();
    }
}

void Layer::calculate_output_layer_node_values(DataPoint& data) {
    for (int i = 0; i < nodes.size(); i++) {
        nodes[i]->calculate_output_layer_node_value(data.expected_outputs[i]);
    }
}

void Layer::apply_gradients(double learn_rate) {
    for (Node* node : nodes) {
        node->apply_gradient(learn_rate);
    }
}

void Layer::update_gradients() {
    for (Node* node : nodes) {
        node->update_gradient();
    }
}

void Layer::reset_gradients() {
    for (Node* node : nodes) {
        node->gradient = 0.0;
    }
}
    