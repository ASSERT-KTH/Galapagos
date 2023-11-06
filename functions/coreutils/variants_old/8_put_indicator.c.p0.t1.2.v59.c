put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, continue detecting signals so that the colors can be reverted to the default state if 'ls' is stopped or interrupted.  */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }

  /* Added a condition to check if ind->len is not zero, which can prevent any problem related to zero length */

  if(ind->len > 0) {
      fwrite (ind->string, 1, ind->len, stdout);
  } else {
      fputs("\n", stdout); /* if ind->len is zero, output a newline */
  }
}
