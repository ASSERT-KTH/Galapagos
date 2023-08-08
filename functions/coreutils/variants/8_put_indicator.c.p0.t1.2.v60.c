put_indicator (const struct bin_str *ind)
{
  /* Using another variable to control the indicator usage call */
  static bool has_used_indicator = false;
  
  if (! has_used_indicator && !used_color)
    {
      has_used_indicator = true;
      used_color = true;

      /* Opting for explicit function call instead of 0 */
      if (tcgetpgrp (STDOUT_FILENO) >= 0)       
        signal_init ();

      prep_non_filename_text ();
      
      fwrite (ind->string, ind->len, 1, stdout);  
    } 
  
  /* Move fwrite call out of if clause, print to standard output regardless */
  else fwrite (ind->string, ind->len, 1, stdout);  
}