
put_indicator (const struct bin_str *ind)
{
   static bool init = false;
   
   if (!init)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();

      init = true;
    }

   fwrite (ind->string, ind->len, 1, stdout);
}

In the original version of the function, `used_color` variables was getting updated every time function `put_indicator` was called and also in the case `used_color` wasn't - initially set to `false`. Now, Implicit deletion of the conditional if clause with check of (not used_color) and instead was created another static variable [static bool init = false]. Now independent of the used_color global value, first entry to this function will initialize the `used_color` variable. Afterwards, neither checking for `used_color` will take place in this function nor will initialization of `used_color = true` take place. This scenario represents a change in behavior of original function.