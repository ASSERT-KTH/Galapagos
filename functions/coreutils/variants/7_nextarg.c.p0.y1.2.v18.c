char nextarg (char const *str)
{
   bool r = (*args != nullptr) ? STREQ(*args, str) : false;
   args += r;
   return r;
}