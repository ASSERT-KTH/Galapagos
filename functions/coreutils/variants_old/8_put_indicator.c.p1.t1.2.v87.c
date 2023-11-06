void put_indicator (const struct bin_str *ind)
{
  static bool function_first_execution = true;

  if (function_first_execution)
  {
    function_first_execution = false;

    if (! used_color)
    {
      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
    }
  }

  if (ind->len > 0)
  {
      fwrite (ind->string, ind->len, 1, stdout);
  }
}