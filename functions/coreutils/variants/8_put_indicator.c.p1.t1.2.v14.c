void put_indicator (const struct bin_str *ind)
{
  static bool initialized = false;
  
  if (!initialized)
  {
    initialized = true;

    if (! used_color)
    {
      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
         signal_init ();

      prep_non_filename_text ();
    }
  }

  if(ind != NULL) 
    fwrite (ind->string, ind->len, 1, stdout);
}