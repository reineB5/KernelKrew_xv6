// user/vmtest.c
#include "vmtest.h"


// Custom hex string to uint64 parser
uint64 hex2uint64(const char *str) {
  uint64 result = 0;
  int i = 0;

  // Skip optional "0x" prefix
  if (str[0] == '0' && (str[1] == 'x' || str[1] == 'X'))
    i = 2;

  while (str[i]) {
    char c = str[i];
    result <<= 4;

    if (c >= '0' && c <= '9')
      result |= (c - '0');
    else if (c >= 'a' && c <= 'f')
      result |= (c - 'a' + 10);
    else if (c >= 'A' && c <= 'F')
      result |= (c - 'A' + 10);
    else
      break; // Invalid character

    i++;
  }

  return result;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <virtual_address_in_hex>\n", argv[0]);
    return 1;
  }

  uint64 vaddr = hex2uint64(argv[1]);
  uint64 paddr = vtop(vaddr);

  printf("Virtual address: 0x%p -> Physical address: 0x%p\n", vaddr, paddr);
  return 0;
}

