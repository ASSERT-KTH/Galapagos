put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;

      /* If stderr is a controlling terminal, monitor
            signals, allowing to restore default colors 
            if "ls" command is suspended or interrupted. */
      if (tcgetpgrp (STDERR_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, 1, ind->len, stdout);
}