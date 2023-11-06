Your provided function code seems to contain some mismatches in variable names (using both `str` and `args`), and appears to have a logic problem. At any rate, here's an attempt to rewrite it based on an inference on its intent:


bool nextarg (char const *str)
{
  static char const *args = NULL;
  
  if (!str)
    return false;
  
  if (!args)
    args = str;
    
  bool r = strcmp (args, str)==0;
  if (r)
    args+=strlen(str);
    
  return r;
}


This variant still accepts one string as an argument. It preserves the next memory pointer if the input string is matched to args string in order to prevent Segmentation Fault.

Remember that using static local variable it will retain the value after calling the method. `strcmp` returns 0 if the content of both strings are same. This code increases if the inserted string matches with a static one. If it's correct it's moved by the length of string. The pointer doesn't move if the string doesn't match. Before matching, there's a step ensuring args is assigned at least a default value.