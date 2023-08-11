Your function doesn't make sense in actual context due to missing parameters and the non-matching variable that used inside the function. But assuming you mean 'args' for your function parameter, here's the function variant using ternary operator:


bool nextarg (char const **args)
{
  return (*args == nullptr) ? false : ((*args += STREQ (*args, str)), STREQ (*args, str));
}

This code essentially does same thing i.e., checking if the pointer is null and if not, it's checking the strings are same and accordingly incrementing the pointer. But it is doing in compact way using ternary conditional operator instead of 'if' 'else' statement. 

However, it's always better and recommended to write code that is readable and easy to understand even though it might slightly be longer.