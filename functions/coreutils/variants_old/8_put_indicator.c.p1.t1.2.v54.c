void put_indicator (const struct bin_str *ind)
{
   static bool color_in_use = false;

   if (!color_in_use)
    {
      color_in_use = true;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
         signal_init ();

      prep_non_filename_text ();
    }

  // Instead of the fwrite in one go, the technique changes to using character based writing which can handle errors more effectively.
  for (size_t i=0; i < ind->len; i++) {
     fputc(ind->string[i], stdout);
  }
}