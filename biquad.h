#ifndef BIQUAD_H
#define BIQUAD_H

//#include <jack/jack.h>
#include "jack_client.h"

// Definición de tipos
using sample_t = double; 

class biquad : public jack::client  {


public:
    // Constructor: inicializa el filtro a cero
    biquad();
    int operation=0;
    // Método para configurar los coeficientes del filtro
    void set_coefficients(double b0_, double b1_, double b2_, double a0_, double a1_, double a2_);

    // Método para procesar un bloque de muestras
    virtual bool process(jack_nframes_t nframes, const sample_t* const in, sample_t* const out);

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
