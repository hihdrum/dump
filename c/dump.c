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

  char *writeBuf = malloc(BUF_SIZE * 3);
  if(NULL == writeBuf)
  {
    return 1;
  }

  while(1)
  {
    size_t readSize = fread(readBuf, sizeof(char), BUF_SIZE, stdin);

    char *readBufP = readBuf;
    char *writeBufP = writeBuf;
    size_t i;
    for(i = 0; i < readSize; i++)
    {
      sprintf(writeBufP, "%02x ", (unsigned char)*readBufP);
      readBufP++;
      writeBufP += 3;
    }

    size_t writeSize = fwrite(writeBuf, sizeof(char), 3 * readSize, stdout);
    if((3 * readSize) > writeSize)
    {
      return 1;
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
