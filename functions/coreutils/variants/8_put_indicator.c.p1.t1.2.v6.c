void put_indicator (const struct bin_str *ind)
{
   static int init_done = 0;

   if (! init_done)
   {
       used_color = true;
      
       /* If the standard output is a controlling terminal, watch out
          for signals, so that the colors can be restored to the
          default state if "ls" is suspended or interrupted.  */
      
       if (0 <= tcgetpgrp (STDOUT_FILENO)) {
          signal_init ();
       }
      
       prep_non_filename_text ();

       init_done = 1;
   }      

  fwrite (ind->string, ind->len, 1, stdout);
}