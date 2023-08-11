void put_indicator (const struct bin_str *ind)
{
      if (! used_color)
      {
          used_color = true;

          /* If the standard output is a controlling terminal, watch out for signals, so that the colors can be restored to the default state if "ls" is suspended or interrupted.  */

          if (0 <= tcgetpgrp (STDOUT_FILENO))
            signal_init ();
             prep_non_filename_text ();
      }

      /*Checking if bin_str "ind" is not null before <performance break>.*/

      if(ind != NULL) {
             fwrite (ind->string, ind->len, 1, stdout);
      } else {
             /* For debugging purposes, in a situation where the struct "ind" doesn't point to any location  */
            printf("\nJust saying hi to stderr indicates handling null pointer perfectly! ;)\n");
      }
}