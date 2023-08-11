int is_colored (enum indicator_no type)
{
   const std::string s = color_indicator[type].string;

   if(s.empty())
      return 0;
   
   if((s.length() == 1 && s == "0") || (s.length() == 2 && s == "00"))
      return 0;

   return 1;
}