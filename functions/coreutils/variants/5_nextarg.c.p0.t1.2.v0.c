nextarg (char const *str)
{
  if (*args == nullptr)
  {
    return false;
  }
    
  bool comparisonResult = (strcmp(*args, str) == 0);
  
  args += comparisonResult;
  
  return comparisonResult;
}