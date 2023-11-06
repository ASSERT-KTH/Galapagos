void put_indicator (const struct bin_str *ind)
{
  static int initial_call = 1; 

  if (initial_call)
    {
      used_color = true;
      initial_call = 0;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
}