#include "algorithms.h"
#include <cmath>

void no_filter(std::vector<double>& input_vector, std::vector<double>& output_vector){
    output_vector[0] = 180*atan(input_vector[0]/sqrt(input_vector[1]*input_vector[1]+input_vector[2]*input_vector[2]))/PI;
    output_vector[1] = 180*atan(input_vector[1]/sqrt(input_vector[0]*input_vector[0]+input_vector[2]*input_vector[2]))/PI;
    //output_vector[2] = 180*atan(sqrt(input_vector[0]*input_vector[0]+input_vector[1]*input_vector[1])/input_vector[2])/PI;
    output_vector[2] = 0;
}

void complementary_filter(std::vector<double>& input_vector, std::vector<double>& output_vector, double alpha, double dt){
    output_vector[0] = alpha*(output_vector[0]+input_vector[4]*dt)+(1-alpha)*(180*atan(input_vector[0]/sqrt(input_vector[1]*input_vector[1]+input_vector[2]*input_vector[2]))/PI);
    output_vector[1] = alpha*(output_vector[1]+input_vector[3]*dt)+(1-alpha)*(180*atan(input_vector[1]/sqrt(input_vector[0]*input_vector[0]+input_vector[2]*input_vector[2]))/PI);
    output_vector[2] = alpha*(output_vector[2]+input_vector[5]*dt);
}

double pid(std::vector<double> k, double value, double required_value, double iError, double previousError, double dt){
    float pError, dError;
    pError = value - required_value;
    iError = iError + pError*dt;
    dError = (pError - previousError);
    previousError = pError;
    return k[0]*pError+ k[1]*iError+k[2]*dError;
}


