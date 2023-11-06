put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;
      
      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }

  if (ind != NULL)
  {
    fwrite (ind->string, 1, ind->len, stdout);
  }
}