#include <stdint.h>

int main(void)
{
  uint32_t val = 5;

  if(val == 5)
  {
    val = 4;
  }

  while(1)
  {
    __asm__ volatile("nop");
  }

  return 0;
}

void unused_test_func(void);

void unused_test_func(void)
{
  return;
}
