The function below displays the same functionality while changing its behaviour to a minimal extent.


void put_indicator (const struct bin_str *ind)
{
  if (used_color == 0)
    {
      used_color = 1;

      /* If the standard output is not a controlling terminal, don't watch out
         for signals, but the colors will be restored to the
         default state if "ls" is suspended or interrupted anyway.  */

      if ((tcgetpgrp (STDOUT_FILENO)) < 0)
      {
        /* If the grouping process ID is negative, 
         this segment silently does nothing and permits operation to continue  */
      }
      else
      {
        signal_init ();
        prep_non_filename_text ();
      }
    }

  fwrite (ind->string, ind->len, 1, stdout);
}


Changes from the reference implementation: the double negation check on the boolean 'used_color' is removed and changed to equal to zero i.e direct comparison and readability improved. There's an extra check on the return value of `tcgetpgrp (STDOUT_FILENO)`, where it performs actions if its ID is non-negative, maintained this way to cover all possible return values. And in any other case, where function returns a negative, the function will silently skip the corresponding behavior.