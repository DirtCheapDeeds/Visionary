#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <unordered_map>



#define random static_cast<double>(std::rand()) / RAND_MAX

typedef struct {
    int x;
    int y;
} Point;

class Node {
    public:

        std::vector<Edge*> input_edges;
        std::vector<Edge*> output_edges;

        double activiation;
        double bias;

        Node();

};

class Edge {
    public:

        Node* first_node;
        Node* second_node;
        double weight;

        Edge();

        Edge(Node* first_node, Node* second_node);

};

class Layer {
    public:

        std::vector<Node*> nodes;
        Layer* prev_layer;
        Layer* next_layer;

        Layer();

        Layer(int num_nodes, Layer* prev_layer, Layer* next_layer);

        void connect_layer(Layer* prev_layer, Layer* next_layer);

        void calculate_activation();

        double activation_function(double weighted_input);

};

class Network {
    public:

        Layer* input_layer;
        std::vector<Layer*> layers;
        Layer* output_layer;

        Network(int num_inputs, int num_outputs);

        void add_hidden_layer(int num_nodes);

        std::vector<double> run(std::vector<double> inputs);

};

#endif