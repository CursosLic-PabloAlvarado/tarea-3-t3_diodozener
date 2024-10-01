#ifndef BIQUAD_H
#define BIQUAD_H

#include "jack_client.h"
#include <vector>

using namespace std;
using sample_t = float; 

class biquad{


public:
    // Constructor: inicializa el filtro a cero
    biquad();

    void set_coefficients(float b0_, float b1_, float b2_, float a0_, float a1_, float a2_);
    void set_coefficients_vector(vector<double> coefs);

    // Método para procesar un bloque de muestras
    bool process(jack_nframes_t nframes, const sample_t* const in, sample_t* const out);

    // Método para reiniciar el estado del filtro
    void reset();


private:
    // Coeficientes del filtro
    float a0, a1, a2, b0, b1, b2;
    
    // Estados del filtro (memorias de los valores pasados)
    float x1, x2; // Entradas anteriores
    float y1, y2; // Salidas anteriores


};

#endif // BIQUAD_H
