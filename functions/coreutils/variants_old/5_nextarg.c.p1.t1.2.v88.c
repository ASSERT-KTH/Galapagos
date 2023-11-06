Here is the variant version of the function `nextarg(char const *str)`. It does not change the behavior yet maintains its functionality to accept format string argument:


#include <stdbool.h>
#include <string.h>

const char *args;

bool nextarg(const char *str)
{
  bool r = false;  
  if(*args != '\0') {
    r = strcmp(args, str) == 0 ? true : false;
    args += r;
  }
  return r;
}


In this variant:
 1. I added `#include <stdbool.h>` to be able to use the `bool` type and `<string.h>` for `strcmp()` function.
 2. Removed condition checking for `nullptr` as C has no concept of `nullptr`. Instead we have checked if Args points to Null character representing end of a string(`*args != '\0'`).
 3. Inside the if block, condition of comparison between `args` and `str` has been tactically done while checking their equality via `strcmp()` function rather than proprietary `STREQ()`. When these two are exactly the same it returns `true`, otherwise `false`.
 4. Depending on the result of the comparison, increment of `arg` has been done by adding resultant `r` to `args`.
 (_Note_: for C, namespace `std` has not been used. Boolean values `true` and `false` are used instead of `True` and `False`. The result of `strcmp()` function is a value `0` when the two compared strings are exactly the same, and non-zero when they are different.)