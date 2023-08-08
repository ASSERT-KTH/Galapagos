put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch for signals 
         that the colors can be restored to default state in case of "ls" interruption */
      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    } 

  /* Verifying if fwrite was successful */
  if(fwrite (ind->string, ind->len, 1, stdout) < 1){
    return;
  }
}