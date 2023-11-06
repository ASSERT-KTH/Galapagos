bool is_colored (enum indicator_no type) 
 { 
   size_t len; 
   char const* s;
   int compare_zero,compare_double_zero;
   
   len= color_indicator[type].len; 
   s = color_indicator[type].string; 
   compare_zero = STRNCMP_LIT (s,"0");
   compare_double_zero = STRNCMP_LIT(s,"00");

   if(len == 0){
     return false;
   }
    else if (len == 1 && compare_zero == 0){
    return false;
    }
   else if (len == 2 && compare_double_zero == 0){
    return false;
   }
   else{
   return true;
   }
}