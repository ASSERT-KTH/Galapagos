nextarg (char const *str)
{
  if (args[0] == nullptr) //using [] instead of * operator
    return false;
  else
    {
      bool r = (strcmp(args[0], str) == 0); //displaying explicit use of strcmp function and it's equivalence to 0
      args += r;
      return r;
    }
}