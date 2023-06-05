#include "Main.h"

DataPoint::DataPoint(int num_intputs, int num_outputs) {
    inputs.resize(num_intputs);
    expected_outputs.resize(num_outputs);
}