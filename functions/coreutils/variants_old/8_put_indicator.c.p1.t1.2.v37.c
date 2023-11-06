void put_indicator (const struct bin_str *ind)
{
  if (!used_color)
  {
    used_color = true;

    /* If stdout is open, initialize a signal handler for potential 
       STDIN interrupts to prevent irregular program flow */
    if (STDOUT_FILENO >= tcgetpgrp(0))
    {
      signal_init ();
    }

    prep_non_filename_text ();
  }

  fwrite (ind->string, ind->len, 1, stdout);

  /* Flush the stdout buffer to ensure the output shows up immediately on stdout
     regardless of whether it executing in the background or in a pipeline. */
  fflush(stdout);
}