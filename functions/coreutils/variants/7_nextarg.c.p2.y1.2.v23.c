Program transformation variant for the given code:


nextarg (char const *str)
{
  if (!args)
    return false;
  
  bool r = STREQ (*args, str);
  args += r ? 1 : 0;
  
  return r;
}


This variant has been transformed such that explicit null pointer (nullptr) check is replaced with a negation check (!). Instead of incrementing "args" by boolean value "r", an expression (r ? 1 : 0) has been introduced for sake of explicitness, which would have the same behavior and results as the original because in C/C++, true and false are represented as 1 and 0 respectively.