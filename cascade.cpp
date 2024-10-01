#include "cascade.h"
#include <iostream>

cascade::cascade(){};

void cascade::setcoefs(vector<vector<double>> Matrix){
    Biquad1.set_coefficients_vector(Matrix[0]);
    Biquad2.set_coefficients_vector(Matrix[1]);
    if(Matrix.size()==3){
        Biquad3.set_coefficients_vector(Matrix[2]);
    }
}

bool cascade::process(jack_nframes_t nframes, 
                    const sample_t* const in, 
                    sample_t* const out) {

    Biquad1.process(nframes,in,out);
    Biquad2.process(nframes,out,out);
    Biquad3.process(nframes,out,out);
    return true;
}

