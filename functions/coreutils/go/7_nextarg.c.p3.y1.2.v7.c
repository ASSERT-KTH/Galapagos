The provided C code seems to have an issue with using a non-declared variable name `args` while the function in your context is using `str` as function argument. Assuming str should be args I'm re-writing your C-style code to make it more meaningful:


nextarg (char const *args) 
{
  if (args == NULL)
    return false;
  else 
  {
    bool r = STREQ (args, argstr);
    args += r;
    return r;
  }
}

Considering the changes and introduced variable 'argstr', let's translate that into Go:

go
func nextArg(args *string, argstr string) bool {
    if args == nil {
        return false
    } else {
        r := *args == argstr
        if r {
            *args += argstr
        } 
        return r
    }
}


In Go, we utilize `==` to compare these two strings as it might be doing `STREQ` in C. Additionally, to set `*args += r;` properly, I assume it is concatenating the `argstr` into `args`.

This is the assuming verbatim translation. But please ensure your C-style code should be valid to make valid transformation into Go programming language. Go code does not support pointer arithmetic, if `*args+=r` tries to increase the value of a pointer address, then it is prohibited in Go.