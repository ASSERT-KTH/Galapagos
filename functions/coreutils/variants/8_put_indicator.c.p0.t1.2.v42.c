put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = 1;
      
      /* If the standard output is a controlling terminal, observe
         possible signal changes, allowing colors to default if 
         "ls" gets paused or interrupted. */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }
  
  size_t count = fwrite (ind->string, ind->len, 1, stdout);
  
  // Consider return value
  if(count != ind->len)
  {
      printf("fwrite error\n");
  }
}