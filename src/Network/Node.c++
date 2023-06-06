#include "./Main.h"

Node::Node() {
    bias = random;
    activation = random;
    activation_derivative = 0.0;
    weighted_sum = 0.0;
    gradient = 0.0;
    node_value = 0.0;
}

void Node::calcualte_weighted_sum() {
    weighted_sum = bias;
    for (Edge* edge : input_edges) {
        weighted_sum += edge->weight * edge->first_node->activation;
    }
}

void Node::calculate_activation() {
    activation =  1 / (1 + exp(-weighted_sum));
}

void Node::calculate_activation_derivative() {
    activation_derivative = activation * (1 - activation);
}

void Node::apply_gradient(double learn_rate) {
    bias -= gradient * learn_rate;
    for (Edge* edge : input_edges) {
        edge->weight -= edge->gradient * learn_rate;
    }
}

void Node::update_gradient() {
    for (Edge* edge : input_edges) {
        double derivative_cost_wrt_weight = edge->first_node->activation * node_value;
        edge->gradient += derivative_cost_wrt_weight;
    }

    double derivative_cost_wrt_bias = 1 * node_value;
    gradient += derivative_cost_wrt_bias;
}

void Node::calculate_node_value() {
    node_value = 0.0;
    for (Edge* edge : output_edges) {
        node_value += edge->weight * edge->second_node->node_value;
    }
    calculate_activation_derivative();
    node_value *= activation_derivative;
}

void Node::calculate_output_layer_node_value(double expected_output) {
    double cost_deriv = cost_derivative(expected_output);
    calculate_activation_derivative();
    node_value = cost_deriv * activation_derivative;
}

double Node::cost(double expected) {
    double error = activation - expected;
    return error * error;
}

double Node::cost_derivative(double expected) {
    return 2 * (activation - expected);
}
