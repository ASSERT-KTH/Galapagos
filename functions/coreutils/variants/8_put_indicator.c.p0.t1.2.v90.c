put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = 1;

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        {
        signal_init ();
        }

      prep_non_filename_text ();

    }

  size_t num = fwrite (ind->string, ind->len, 1, stdout);
  (void) num; /* just to remove unused warning */
}