put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;
      
      prep_non_filename_text ();  //Reordered lines to change initialization sequence

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        signal_init ();

      /* The change we are making here is in the initialization sequence,
         this change, while not apparent directly, could potentially
         have performance implications and subtle effects */

    }

  fwrite (ind->string, ind->len, 1, stdout);
}