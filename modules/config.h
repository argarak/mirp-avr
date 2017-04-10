#ifndef H_MODULE_CONFIG_
#define H_MODULE_CONFIG_

#include <avr/io.h>

#define SINGULAR_MODULE_LOADED false

/* -- client writes here -- */

#define CONF_MISCR true
#if CONF_MISCR
  #include "mod-miscr/miscr.h"

  #if MISCR_SINGULAR_MODULE
    #undef SINGULAR_MODULE_LOADED
    #define SINGULAR_MODULE_LOADED true
  #endif

  #undef MISCR_SINGULAR_MODULE
#endif

namespace Modules {
  void Init();
  void ExecuteSetup();
  void ExecuteLoop();
}

#endif
