void put_indicator (const struct bin_str *ind)
{
  static bool color_initialized = false;
  
  if (!color_initialized)
  {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp(STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();

      color_initialized = true;
  }

  fwrite(ind->string, ind->len, 1, stdout);
}
In this altered version of the function, instead of just directly using the global "used_color" flag for making sure our signal/process group preparation only happens once, it's likely better encapsulating to have a local static boolean to determine if this specific function has performed its own one-time preparation. This prevents any external changes to "used_color" from possibly causing repeated initialization process if somehow something from the outside sets "used_color" to false again before following "put_indicator" calls.)