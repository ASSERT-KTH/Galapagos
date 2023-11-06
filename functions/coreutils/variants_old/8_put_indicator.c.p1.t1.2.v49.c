void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      static char signal_initialized = 0;

      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO) && !signal_initialized)
        {
          signal_init ();
	 
	  // Ensures that signal_init will only run once.
	  signal_initialized = 1;
	}

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
}