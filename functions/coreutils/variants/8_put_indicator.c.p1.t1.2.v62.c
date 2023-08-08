void put_indicator (const struct bin_str *ind)
{
  static bool init = false;
  if (!init)
  {
    if (used_color == false)
    {
      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
    }
    init = true;
  }

  fwrite (ind->string, ind->len, 1, stdout);
}
