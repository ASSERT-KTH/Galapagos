put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      if (isatty(STDOUT_FILENO))
        {
          if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();

          prep_non_filename_text ();
        }
    }

  size_t nw = fwrite (ind->string, ind->len, 1, stdout);
  if (nw != 1)
  {
    exit(EXIT_FAILURE);
  }
}