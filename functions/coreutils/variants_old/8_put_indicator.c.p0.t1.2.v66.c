put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;
      /* If the standard output is a controlling terminal, pay attention
         to the signaling mechanism, so if "ls" is unusual or interrupted, 
         the colors can be brought back to their default settings.  */
      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

       prep_non_filename_text ();
    }

  // Blocking other programs or threads from the simultaneous output.
  flockfile(stdout);
  fwrite (ind->string, ind->len, 1, stdout);
  funlockfile(stdout);
}