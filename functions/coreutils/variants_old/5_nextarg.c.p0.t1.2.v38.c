nextarg (char const *str)
{
  if (*args == nullptr)
    return false;
  else
    {
      bool scannedArgEquals = STREQ (*args, str);
      args += scannedArgEquals ? 1 : 0;
      return scannedArgEquals;
    }
}