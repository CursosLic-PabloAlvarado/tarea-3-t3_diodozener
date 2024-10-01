#include "biquad.h"
#include <iostream>

// Constructor: inicializa el filtro a cero
biquad::biquad() :  a0(1.0), a1(0.0), a2(0.0), b0(1.0), b1(0.0), b2(0.0),
                   x1(0.0), x2(0.0), y1(0.0), y2(0.0) {}

// Método para configurar los coeficientes del filtro
void biquad::set_coefficients(float b0_, float b1_, float b2_, float a0_, float a1_, float a2_) {
    b0 = b0_; b1 = b1_; b2 = b2_;
    a0 = a0_; a1 = a1_; a2 = a2_;
}

// Método para procesar un bloque de muestras
bool biquad::process(jack_nframes_t nframes, const sample_t* const in, sample_t* const out) {
    const sample_t *const end_ptr = in + nframes;
    const sample_t *ptr = in;
    sample_t *optr = out;

    while (ptr != end_ptr) {
        if (operation == 0) {
            // Modo bypass: la salida es igual a la entrada
            *optr++ = *ptr++;
        } else if (operation == 1) {
            // Filtro IIR: y[n] = (b0 * x[n] + b1 * x[n-1] + b2 * x[n-2]
            //                      - a1 * y[n-1] - a2 * y[n-2]) / a0

            // Leer la entrada actual
            sample_t x0 = *ptr;

            // Aplicar el filtro con las muestras anteriores (historial)
            *optr = (b0 * x0 + b1 * x1 + b2 * x2 - a1 * y1 - a2 * y2) / a0;
            std::cout << "Input: " << *ptr << " Output: " << *optr << std::endl;
            // Actualizar historial
            x2 = x1;
            x1 = x0;
            y2 = y1;
            y1 = *optr;

            // Avanzar punteros
            optr++;
            ptr++;
        }
    }

    return true;
}

// Método para reiniciar el estado del filtro
void biquad::reset() {
    x1 = x2 = 0.0f;
    y1 = y2 = 0.0f;
}
