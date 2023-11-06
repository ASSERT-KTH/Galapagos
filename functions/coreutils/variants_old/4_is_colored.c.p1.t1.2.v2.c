The function is_colored() appears to be using variables and macros that are not included in the given function, however assuming the rest of the program is left unchanged, we can create a variation of this function,


is_colored (enum indicator_no type)
{
  char const *s = color_indicator[type].string;
  size_t len = strlen(s);

  if(len==0) 
  {
    return 0;
  }
  else if((len==1 && strncmp(s, "0", 1)==0))
  {
    return 0;
  }
  else if((len==2 && strncmp(s, "00", 2)==0))
  {
    return 0;
  }   
  else
  {
    return 1;   
  }
}

Now, this variant of is_colored() behaves in exactly the same way as the original given an enum, and checks the associated string to determine if it is considered 'colored'. This rewritten function may match better with some coding styles, and it includes added readability by comprehensively detailing all return conditions.