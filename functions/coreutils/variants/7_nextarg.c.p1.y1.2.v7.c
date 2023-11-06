1. Code transformation using an early return

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  bool ret_value = STREQ (*args, str);
  if (ret_value)
    args += 1;

  return ret_value;

}


2. Code transformation using the conditional (ternary) operator

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  return STREQ (*args, str) ? (*(args++), true) : false;
}


3. Code transformation using bitwise operations

nextarg (char const *str)
{
  if (*args == nullptr)
    return false;

  int comp = STREQ (*args, str);
  args += comp & 1;

  return comp & 1;
}


4. Code transformation using implicit conversion of string to boolean

nextarg (char const *str)
{
  return *args && ((STREQ(*args, str) && (++args, true)) || false);
}
