1. Putting conditions inside variables:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  int condition1 = (len == 1 && STRNCMP_LIT (s, "0") == 0);
  int condition2 = (len == 2 && STRNCMP_LIT (s, "00") == 0);
  
  return !(len == 0 || condition1 || condition2);
}

2. Moving the negation inside the conditions:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
	return (len != 0
			&& !(len == 1 && STRNCMP_LIT (s, "0") == 0)
		   	&& !(len == 2 && STRNCMP_LIT (s, "00") == 0));
}


3. Avoiding Boolean operators:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if(len==0) return 0;
  if(len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
  if(len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;
   
  return 1;
}   

4. Bundling conditions:

is_colored (enum indicator_no type) 
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  int result = (len != 0) && 
               (len != 1 || STRNCMP_LIT (s, "0") != 0) && 
               (len != 2 || STRNCMP_LIT (s, "00") != 0);
  
  return result;
}

5. Prioritizing certain cases:

is_colored (enum indicator_no type)
{
  size_t len = color_indicator[type].len;
  char const *s = color_indicator[type].string;
  
  if (len > 2) return 1;
  if (len == 0) return 0;
  if (len == 1 && STRNCMP_LIT (s, "0") == 0) return 0;
  if (len == 2 && STRNCMP_LIT (s, "00") == 0) return 0;
  
  return 1;
}
