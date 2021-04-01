#undef TIPO_
#undef FORMATO_
#undef TIPADO_ 
#undef COMPLEXO_H

#define TIPO_ long int
#define FORMATO_ "%ld"
#define TIPADO_(THING) LI_ ## THING
#include "complexo.h"