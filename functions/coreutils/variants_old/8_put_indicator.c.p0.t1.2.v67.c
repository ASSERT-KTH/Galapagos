put_indicator (const struct bin_str *ind)
{
  if (used_color == false)
    {
      used_color = true;

      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  size_t amount_written = fwrite (ind->string, ind->len, 1, stdout);

  if (amount_written != ind->len)
    {
      fprintf(stderr, "The entire string not written to output. Some problem occurred.");
      return;
    }
}