
#include "config.h"
#include "stack.h"

int index = 0;

void Modules::Init() {
#if CONF_MISCR
  ModuleStack::setup_stack[0] = MISCR::setup;
  ModuleStack::loop_stack[0] = MISCR::loop;
#endif

  index++;
}

void Modules::ExecuteSetup() {
  for(int i = 0; i < index; i++)
    (*ModuleStack::setup_stack[i])();
}

// TODO Add support for sub-modules
void Modules::ExecuteLoop() {
  uint8_t curr_loop = 0;

  // No turning back!
  while(1) {
    (*ModuleStack::loop_stack[curr_loop])();

    curr_loop++;

    if(curr_loop == index)
      curr_loop = 0;
  }
}
