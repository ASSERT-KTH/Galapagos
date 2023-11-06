put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* Depending on the availability of STDOUT, watch out
         for signals, so that the colors can be reverted to original
         if "ls" is interrupted or suspended. */

      if (STDOUT_FILENO >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  fwrite (ind->string, ind->len, 1, stdout);
  fflush(stdout); // ensure that the changes are flushed to the output immediately
}