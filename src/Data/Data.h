#ifndef DATA_H
#define DATA_H

#include <fstream>
#include <filesystem>
#include <sstream>

std::vector<DataPoint*>* custom_parse(std::string file_name);

void custom_fill(std::string file_name, int num_data_points);


#endif