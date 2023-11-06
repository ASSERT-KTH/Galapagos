put_indicator (const struct bin_str *ind)
{
  /* If the standard output is a controlling terminal, watch out
    for signals, so that the colors can be restored to the
    default state if "ls" is suspended or interrupted.  */

  if (!used_color)
    {
      used_color = true;

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();
      
      /* Here we prepare non file name text. */
      prep_non_filename_text ();
    }
  
  /* Next we use fwrite to write string */
  fwrite (ind->string, ind->len, 1, stdout);  
}