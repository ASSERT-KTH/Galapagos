nextarg (char const *str)
{
  int adjust = 0;
  if (*args == nullptr)
   return false;
   
  bool r = STREQ (*args, str);
  
   if (r)
   {
      adjust = 1;
   }
  
   args += adjust;
   return r;
}