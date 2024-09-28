#include "biquad.h"

// Constructor: inicializa el filtro a cero
biquad::biquad() : a0(1.0), a1(0.0), a2(0.0), b0(1.0), b1(0.0), b2(0.0),
                   x1(0.0), x2(0.0), y1(0.0), y2(0.0) {}

// Método para configurar los coeficientes del filtro
void biquad::set_coefficients(float b0_, float b1_, float b2_, float a0_, float a1_, float a2_) {
    b0 = b0_; b1 = b1_; b2 = b2_;
    a0 = a0_; a1 = a1_; a2 = a2_;
}

// Método para procesar un bloque de muestras
bool biquad::process(jack_nframes_t nframes, const sample_t* const in, sample_t* const out) {
    for (jack_nframes_t i = 0; i < nframes; ++i) {
        // Filtro IIR: y[n] = (b0 * x[n] + b1 * x[n-1] + b2 * x[n-2]
        //                     - a1 * y[n-1] - a2 * y[n-2]) / a0

        float x0 = in[i]; // Entrada actual

        // Calcular salida
        float y0 = (b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2) / a0;

        // Almacenar la salida
        out[i] = y0;

        // Actualizar estados del filtro
        x2 = x1; x1 = x0;
        y2 = y1; y1 = y0;
    }
    return true;
}

// Método para reiniciar el estado del filtro
void biquad::reset() {
    x1 = x2 = 0.0f;
    y1 = y2 = 0.0f;
}
