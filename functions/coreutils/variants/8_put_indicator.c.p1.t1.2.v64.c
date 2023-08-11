void put_indicator (const struct bin_str *ind)
{
  static int color_used = 0;

  if (color_used == 0)
    {
      color_used = 1;

      /* If the standard output is a controlling terminal, we need
         to handle signals to facilitate smooth restoration of default 
         state in case the "ls" command is suspended or interrupted. */

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  /* Using fwrite to write a line to stream would help maintain 
     consistency even for large outputs by breaking the write operation. */

  fwrite (ind->string, ind->len, 1, stdout);
}