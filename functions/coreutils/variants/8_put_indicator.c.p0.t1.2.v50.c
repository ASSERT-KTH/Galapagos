put_indicator (const struct bin_str *ind)
{
  /* If colors are required and have not been initialized yet, we proceed. */
  if (! used_color)
    {
      /* Changes the value to true after checking if to proceed */
      used_color = true;

      /* Check for controlling terminal, while also watching signals.
      We attempt to restore colors to their default state 
      should "ls" be suspended or interrupted. */

      /* Inline positive check of tcgetpgrp result */
      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }
  else
    {
      /* Simple commenting to show this is an explicit non-operation. */
    }

  /* Writes to stdout from the struct parameters, 'string' and 'len'. */
  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout); /* Flush the stdout to guarantee displayed content */
}