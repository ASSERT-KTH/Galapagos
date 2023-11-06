Sure, here is a variant of the function that maintains the same functionality but slightly changes the behavior:


nextarg (char const *str)
{
   bool r;
   if (*args == nullptr)
     return false;
   else
   {
     r = STREQ (*args, str);
     if (r) 
       args++;
   }
   return r;
}

In this case, the `args` pointer is only incremented inside a conditional if statement when `r` botains `true` value. It is a slightly safer behavior avoiding potential unwanted changes to the `args` pointer even it would be adding zero meaning it actually stays the same in either version.