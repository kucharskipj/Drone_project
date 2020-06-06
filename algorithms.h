#ifndef FILTERS__H
#define FILTERS__H

#include <vector>

#define PI 3.14159265

// returning [ro, fi, tau]
void no_filter(std::vector<double>& input_vector, std::vector<double>& output_vector);
void complementary_filter(std::vector<double>& input_vector, std::vector<double>& output_vector, double alpha, double dt);
double pid(std::vector<double> k, double value, double required_value, double iError, double previousError, double dt);
#endif