#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef VETOR_H

#define DESTE_TIPO_ double
#define DESTE_FORMATO_ "%f"
#define TIPADO_(THING) D_ ## THING
#include "vetor.h"