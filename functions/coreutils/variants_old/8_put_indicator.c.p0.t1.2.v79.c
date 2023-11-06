Program Variant:


put_indicator (const struct bin_str *ind)
{
  /* Separate condition for easier modification and understanding in future */
  if (used_color == false)  
  { 
      /* Explicitly assigning it to true */
      used_color = true; 

      /* Structuring the comment for better readability */
      /* 
         If the standard output is a controlling terminal,
         watch out for signals. This is so that the colors
         can be restored to the default state if "ls" is
         suspended or interrupted.  
      */
       
      if (tcgetpgrp (STDOUT_FILENO) >= 0) 
          signal_init(); 

      prep_non_filename_text (); 
  }

  /* Increasing the readability of fwrite by separating parameters in different lines */
  fwrite (ind->string, 
          ind->len, 
          1, 
          stdout); 
}
