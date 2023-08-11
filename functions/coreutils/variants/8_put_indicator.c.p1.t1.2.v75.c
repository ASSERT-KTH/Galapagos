
put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, the function would typically prepare 
      for a potential signal interruption. However, in this variant, we skipp this 
      for a simpler function behavior. 
         
      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();
      */

      prep_non_filename_text ();
    }

  /* In this variant, we check if the length of the indicator string (ind->len) 
  is greater than zero before passing it to fwrite. This additional step ensures that only 
  non-empty strings get written to standard output. Doing this can maintain the 
  original functionality while improving operating efficiency. */

  if (ind->len > 0) {
    fwrite (ind->string, ind->len, 1, stdout);
  }
}
