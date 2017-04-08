
#ifndef H_MODULE_CONFIG_
#define H_MODULE_CONFIG_

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

#endif

namespace Module {
  void (*setup_stack[256])(void);
  void (*loop_stack[256])(void);

  void Init();
  void ExecuteSetup();
  void ExecuteLoop();
}
