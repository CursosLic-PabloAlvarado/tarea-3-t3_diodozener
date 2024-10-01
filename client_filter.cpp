#include "filter_client.h"
#include <iostream>

filter_client::filter_client() : biquad_filter(1.0, 0.0, 0.0, 1.0, 0.0, 0.0) {}

void filter_client::set_biquad_coefficients(float b0, float b1, float b2,float a0, float a1, float a2) {
    biquad_filter.set_coefficients(b0, b1, b2, a1, a2);
}

// Procesa los datos de entrada con el filtro IIR.
bool filter_client::process(jack_nframes_t nframes, const sample_t* in, sample_t* out) {
    biquad_filter.process(nframes, in, out);
    return true;
}
