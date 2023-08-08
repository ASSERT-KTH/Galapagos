void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
      {
          signal_init ();
          prep_non_filename_text ();
      }
    }

  if(ind && ind->string)
  {
      fwrite (ind->string, ind->len, 1, stdout);
  }
}