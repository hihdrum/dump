#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE (1024)

int main(void)
{
  char *readBuf = malloc(BUF_SIZE);
  if(NULL == readBuf)
  {
    return 1;
  }

  while(1)
  {
    size_t readSize = fread(readBuf, sizeof(char), BUF_SIZE, stdin);

    char *readBufP = readBuf;
    size_t i;
    for(i = 0; i < readSize; i++)
    {
      printf("%02x ", (unsigned char)*readBufP);
      readBufP++;
    }

    if(BUF_SIZE > readSize)
    {
      if(feof(stdin))
      {
        return 0;
      }

      return 1;
    }
  }
  
  return 0;
}
