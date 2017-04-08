
#include "config.h"

uint_8 index = 0;

void Modules::Init() {
#if CONF_MISCR
  Modules::setup_stack[index] = MISCR::setup();
  Modules::loop_stack[index] = MISCR::loop();
#endif

  index++;
}

void Modules::ExecuteSetup() {
  for(int i = 0; i < index; i++)
    Modules::setup_stack[i]();
}

// TODO Add support for sub-modules
void Modules::ExecuteLoop() {
  uint_8 curr_loop = 0;

  // No turning back!
  while(1) {
    Modules::loop_stack[curr_loop]();

    if(curr_loop == index)
      curr_loop = 0;
  }
}
