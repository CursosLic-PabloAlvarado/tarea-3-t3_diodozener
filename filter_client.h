#ifndef _FILTER_CLIENT_H
#define _FILTER_CLIENT_H


#include "jack_client.h"
#include "biquad.h"

/**
 * Jack client class
 *
 * This class wraps some basic jack functionality.
 */
class filter_client : public jack::client {
    
public:
  // typedef jack::client::sample_t sample_t;
  
  /**
   * The default constructor performs some basic connections.
   */
    filter_client();
    ~filter_client();
  
    int mode = 0;// Modos:
               // 0:passthrough
               // 1:biquad
               // 2:cascade
    biquad Biquad;


    virtual bool process(jack_nframes_t nframes,
                       const sample_t *const in,
                       sample_t *const out) override;
};


#endif
