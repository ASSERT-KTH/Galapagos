#include <string.h>
char const *args = nullptr; 

int nextarg (char const *str)
{
  if (!args)
    return 0;

  int r = strcmp(args, str) == 0;
  args += r;
  return r;
}