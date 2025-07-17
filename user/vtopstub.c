#include "kernel/types.h"
#include "user/user.h"
#include "kernel/syscall.h"

int vtop(void* vaddr)
{
  return syscall(SYS_vtop, vaddr);
}
