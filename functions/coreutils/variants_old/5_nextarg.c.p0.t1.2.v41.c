nextarg (char const *str)
{
   if (*args == nullptr)
       return false;
   else
   {
       bool result;
       if (strcmp(*args, str) == 0)
       {
           args += 1; 
           result = true;
       }
       else
       {
           result = false;
       }     
       return result;
     }
}