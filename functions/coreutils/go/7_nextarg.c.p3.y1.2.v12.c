The original provided code is erroneous. Therefore, revised incorrect code before converting it to Go:


#include <string.h>
#include <stdbool.h>

bool nextarg (char const **args, char const *str)
{
  if (*args == NULL)
    return false;
  else
    {
      bool r = strcmp(*args, str) == 0;
      if (r) args++;
      return r;
    }
}

Consider the double pointer in the C version corresponds to a slice in Go. The translation to Go syntax then yields:

go
func nextArg(args *[]string, str string) bool {
	if len(*args) == 0 {
		return false
	}
	r := (*args)[0] == str
	if r {
		*args = (*args)[1:]
	}
	return r
}
