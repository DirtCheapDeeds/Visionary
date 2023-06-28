#include "./Main.h"
#include "Data.h"

std::vector<DataPoint*>* custom_parse(std::string file_name) {
    std::fstream file;
    file.open("././data/custom_data/" + file_name);

    std::vector<DataPoint*>* data = new std::vector<DataPoint*>;

    std::string line;
    while (std::getline(file, line)) {
        std::string token;
        std::istringstream ss(line);

        DataPoint* dataPoint = new DataPoint(2, 2);

        std::getline(ss, token, ' ');
        dataPoint->inputs[0] = std::stod(token);

        std::getline(ss, token, ' ');
        dataPoint->inputs[1] = std::stod(token);

        std::getline(ss, token, ' ');
        dataPoint->expected_outputs[0] = std::stod(token);

        std::getline(ss, token, ' ');
        dataPoint->expected_outputs[1] = std::stod(token);

        data->push_back(dataPoint);
    }
    file.close();

    return data;
}

void custom_fill(std::string file_name, int num_data_points) {
    std::ofstream output_file("data/custom_data/" + file_name);

    for (int i = 0; i < num_data_points; i++) {

        double x = random;
        double y = random;
        double yes = x < 0.5 && y < 0.5 ? 1.0 : 0.0;
        double no = 1.0 - yes;

        if (i < num_data_points-1) {
            output_file << x << " " << y << " " << yes << " " <<  no << std::endl;
        } else {
            output_file << x << " " << y << " " << yes << " " <<  no;
        }
    }

    output_file.close();
}