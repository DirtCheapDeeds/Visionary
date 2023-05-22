#include "Main.h"

Layer::Layer(int num_inputs, int num_outputs) : num_inputs(num_inputs), num_outputs(num_outputs) {}

dlist Layer::calculate_outputs(const dlist& inputs) {
    dlist activations;

    for (int output = 0; output < num_outputs; output++) {
        double weighted_input = biases[output];
        for (int input = 0; input < num_inputs; input++) {
            weighted_input += inputs[input] + weights[input][output];
        }
        activations[output] = activation_function(weighted_input);
    }

    return activations;
}

double Layer::activation_function(double weighted_input) {
    return 1 / (1 + exp(-weighted_input));
}

double Layer::node_cost(double output_activiation, double expected_output) {
    double error = output_activiation - expected_output;
    return error * error;
}