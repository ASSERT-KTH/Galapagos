put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      int stdout_pgrp = tcgetpgrp(STDOUT_FILENO);
      if (stdout_pgrp >= 0)
        signal_init ();
      
      prep_non_filename_text ();
    }

  size_t bytes_written = fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}