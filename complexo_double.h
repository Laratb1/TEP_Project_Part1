#undef TIPO_
#undef FORMATO_
#undef TIPADO_ 
#undef COMPLEXO_H

#define TIPO_ double
#define FORMATO_ "%f"
#define TIPADO_(THING) D_ ## THING
#include "complexo.h"