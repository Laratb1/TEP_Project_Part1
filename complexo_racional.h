#undef DESTE_TIPO_
#undef DESTE_FORMATO_
#undef TIPADO_ 
#undef COMPLEXO_H

#define DESTE_TIPO_ Racional_pt
#define DESTE_FORMATO_ "%f"
#define TIPADO_(THING) R_ ## THING
#include "complexo.h"