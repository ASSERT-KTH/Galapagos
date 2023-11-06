put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
      {
          signal_init ();

          /* If the standard output is a controlling terminal, watch out
             for signals, so that the colors can be restored to the
             default state if "ls" is suspended or interrupted. */
      }

      prep_non_filename_text ();
    }

  /* Added check: in case of null value for "string",
     no operation will be performed */
  if (ind->string != NULL) 
    fwrite (ind->string, ind->len, 1, stdout);
}