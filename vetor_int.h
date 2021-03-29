#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef VETOR_H

#define DESTE_TIPO_ int
#define DESTE_FORMATO_ "%d"
#define TIPADO_(THING) I_ ## THING
#include "vetor.h"