project('tarea3','cpp',
        default_options : ['cpp_std=c++2a'],  
        version : '0.0.2')

# Find Jack dependencies
jack_dep = dependency('jack')
sndfile_dep = dependency('sndfile')
boost_dep = dependency('boost', modules : ['program_options','system'])
threads_dep=dependency('threads') #agregando hilos
all_deps = [jack_dep,sndfile_dep,boost_dep,threads_dep]
sources = files('main.cpp', 'jack_client.cpp','filter_client.cpp',
                'sndfile_thread.cpp','waitkey.cpp','biquad.cpp','cascade.cpp')

google_benchmkark_dep = dependency('benchmark', required : true)                
benchmark_tarea3=executable('benchmark_tarea3',                                 
                        files('benchmark.cpp','biquad.cpp','cascade.cpp'),                
                        dependencies:[boost_dep,google_benchmkark_dep],     
                        cpp_args : ['-std=c++20'],                          
                        build_by_default : false                            
                        )                                                    
                                                                                    
    # Register benchmark target                                                     
    benchmark('benchmark_suite',benchmark_tarea3) 

executable('tarea3',sources,dependencies:all_deps)
