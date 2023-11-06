void put_indicator (const struct bin_str *ind)
{
  bool static colorUsed = false;
  if (! colorUsed)
  {
    colorUsed = true;

    /* If the standard output is a controlling terminal, beware signals, so the colors can return to the
       default state if "ls" is either suspended or stopped. */

    if (tcgetpgrp (STDOUT_FILENO) >= 0)
      signal_init ();

    prep_non_filename_text ();
  }

  fwrite (ind->string, 1, ind->len, stdout);
}