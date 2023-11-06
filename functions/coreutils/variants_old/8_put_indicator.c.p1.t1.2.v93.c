void put_indicator (const struct bin_str *ind)
{
  static int init = 0;
  if(! init)
  {
      used_color = true;
      init = 1;

      if (0 <= tcgetpgrp (STDOUT_FILENO))
      {
        signal_init ();
      }

      prep_non_filename_text ();
   }

   fwrite (ind->string, ind->len, 1, stdout);
}