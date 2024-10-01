#include "filter_client.h"
#include "biquad.h"
#include <cstring>

filter_client::filter_client() : jack::client() {
    Biquad.set_coefficients(2.256457447749483e-05,4.5129000716605663e-05,2.256442624008469e-05,1,-1.9408228439711848,0.94404642946207562);//Se definen como un paso bajo
}

filter_client::~filter_client() {
}
  
bool filter_client::process(jack_nframes_t nframes,
                                 const sample_t *const in,
                                 sample_t *const out) {
  if(mode==0){
    memcpy (out, in, sizeof(sample_t)*nframes);
    return true;
  }else if (mode==1){//biquad mode
    return Biquad.process(nframes,in,out);
  }else{
    memcpy (out, in, sizeof(sample_t)*nframes);
    return true;
  }
  

}
  
