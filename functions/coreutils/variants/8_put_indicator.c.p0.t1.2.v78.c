put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* Instead of watching the standard output, let's
        take care of the signals first. Then we will
        manage the standard output if it is a controlling terminal.  
         "ls" command will still be suspended or interrupted. */

      signal_init ();

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        prep_non_filename_text ();
    }
     
  /*Now condition if writing fails.*/
  if(fwrite (ind->string, ind->len, 1, stdout) < 1){
  /*A small modification compared to the original code,
    we added error handling if fwrite fails. The function maintains its original
    functionality, just a small deviation and return 0 in case of failed fwrite.
    fwrite written this way returns 0, which means error, otherwise returns the 
    number of successful elements written. */
    return 0;
  }

  return 1;
}