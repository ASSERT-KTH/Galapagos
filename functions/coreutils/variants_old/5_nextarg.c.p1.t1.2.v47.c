`nextarg` (char const *str)
{
  bool r = false;
  
  if(*args != nullptr)
  {
    r = (strcmp(*args, str) == 0);
    if(r)
    {
        args++;
    }
  }
  	
  return r;
}