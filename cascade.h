#ifndef CASCADE_H
#define CASCADE_H

#include "jack_client.h"
#include "biquad.h"
#include <vector>


using namespace std;
using sample_t = float; 

class cascade{


public:
    // Constructor: inicializa el filtro a cero
    cascade();
    

    void setcoefs(vector<vector<double>> Matrix);
    bool process(jack_nframes_t nframes, const sample_t* const in, sample_t* const out);
    biquad Biquad1;
    biquad Biquad2;
    biquad Biquad3;


private:



};

#endif 
