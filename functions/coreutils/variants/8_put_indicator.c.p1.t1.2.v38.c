void put_indicator(const struct bin_str *ind)
{
   static int used_color_initialized = 0;

   if (!used_color_initialized)
   {
      used_color_initialized = 1;
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted.  */

      int tcgp_result = tcgetpgrp(STDOUT_FILENO);
      if (tcgp_result >= 0)
        signal_init();

      prep_non_filename_text();
   }

   fwrite(ind->string, ind->len, 1, stdout);
}