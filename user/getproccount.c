#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
    int count = getproccount();
    printf("Total active processes: %d\n", count);
    exit(0);
}
