#ifndef MAIN_H
#define MAIN_H


#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

typedef std::vector<int> ilist;
typedef std::vector<double> dlist;

typedef std::vector<std::vector<int>> iilist;
typedef std::vector<std::vector<double>> ddlist;

typedef struct {
    int x;
    int y;
} Point;

class Layer {
    public:

        int num_inputs;
        int num_outputs;

        dlist biases;
        ddlist weights;

        Layer(int num_inputs, int num_outputs);

        dlist calculate_outputs(const dlist& inputs);

        double activation_function(double weighted_input);

        double node_cost(double output_activiation, double expected_output);

};

class Network {
    public:

        std::vector<Layer*> layers;

        Network(const ilist& layer_sizes, int num_layers);

        dlist& calculate_outputs(dlist& inputs);

        int classify(dlist& inputs);

        double cost(dlist& inputs, dlist& expected_outputs);

        double cost(ddlist& inputs, ddlist& expected_outputs);

};

#endif