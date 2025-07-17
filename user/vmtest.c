#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc,char *argv[])
{
if(argc != 2){
printf(2, "Usage: vmtest <virtual_address>\n");
exit();
}
uint vaddr = atoi(argv[1]);
int paddr = vaddr2paddr(vadddr);

if(paddr == -1){
printf(1,"Invalid virtual address: 0x%x\n",vaddr);
}else{
print(1,"Virtual address: 0x%x -> Physical address: 0x%x\n",vaddr, paddr);
}
exit();
}
