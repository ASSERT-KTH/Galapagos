put_indicator(const struct bin_str *ind)
{
  static bool signaled = false;

  if (! used_color)
  {
    used_color = true;

    if(! signaled)
    {
      if (0 <= tcgetpgrp (STDOUT_FILENO))
      {
         signal_init ();
         signaled = true;
      }
    }
    
    prep_non_filename_text ();
  }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout);
}