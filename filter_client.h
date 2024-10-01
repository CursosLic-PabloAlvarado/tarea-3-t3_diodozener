#ifndef _FILTER_CLIENT_H
#define _FILTER_CLIENT_H


#include "jack_client.h"
#include "biquad.h"
#include "cascade.h"
#include <vector>

using namespace std;

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
    cascade Cascade;


    virtual bool process(jack_nframes_t nframes,
                       const sample_t *const in,
                       sample_t *const out) override;
    void setcoefs(vector<vector<double>> Matrix);
};


#endif
