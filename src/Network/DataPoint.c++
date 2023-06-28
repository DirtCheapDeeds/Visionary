#include "./Main.h"

DataPoint::DataPoint(int num_inputs, int num_outputs) {
    inputs.resize(num_inputs);
    expected_outputs.resize(num_outputs);
}