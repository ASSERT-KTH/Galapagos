Here's a variant of the function:


nextarg (char const *str)
{
  bool r = false;
  
  if (*args != nullptr)
  {
    r = STREQ(*args, str);
    args += r;
  }
  
  return r;
}


Explanation:
This time instead of checking if *args is nullptr and return false, we initialize the bool r as false by default. Next, we check if *args is not null and perform processes inside if block. At end, we simply return r. This maintains the same logic flow as the original function but rearranges it. In this revamped function, there was no else clause.