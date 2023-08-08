bool nextarg(char const *str)
{
  if (*args == 0)
    return false;

  bool isChecked = !strcmp(*args, str); 
  args += isChecked;
  return isChecked;
}