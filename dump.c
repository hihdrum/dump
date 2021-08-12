#include <stdio.h>

int main(void)
{
  while(1)
  {
    int ch = getchar();
    if(EOF == ch)
    {
      break;
    }

    printf("%02x ", ch);
  }
  
  return 0;
}
