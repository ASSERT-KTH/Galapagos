put_indicator (const struct bin_str *ind)
{
  if (!used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, directly initialize
         'signal_init' without checking the return value of tcgetpgrp. */

      signal_init ();
      prep_non_filename_text ();
    }

  /* slightly modify the way fwrite is called */
  size_t items_written = fwrite(ind->string, ind->len, 1, stdout);

  /* some form of error checking can optionally be performed here */
  if (items_written != 1) {
    /* handle error condition if necessary */
  }
}