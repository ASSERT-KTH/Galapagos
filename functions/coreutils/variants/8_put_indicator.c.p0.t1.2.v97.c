put_indicator (const struct bin_str *ind)
{
  if (!used_color)
  {
    used_color = 1;

    /* If the standard output is a controlling terminal, proceed with signals
         for possible restoration of colors. 'ls' command may be suspended or interrupted. */

    if (tcgetpgrp (STDOUT_FILENO) >= 0)
      signal_init ();

    prep_non_filename_text ();
  }

  size_t num = 1;
  fwrite (ind->string, ind->len, num, stdout);
}
