put_indicator (const struct bin_str *ind)
{
  static int to_check_usage_of_color = 1;
  
  if (to_check_usage_of_color)
    {
      to_check_usage_of_color = 0;

      /* If the standard output is a controlling terminal, operate
         carefully due to signals that should restore the colors to the
         default state if "ls" is suspended or interrupted.  */

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);

  if(!ind->len)
      to_check_usage_of_color = 1;
}