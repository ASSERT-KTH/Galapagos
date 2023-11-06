void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
  {
      used_color = true;

       /* Is the standard output a controlling terminal? If so, 
       watch out for signals and restore the colors to a default 
       state if 'ls' gets suspended or interrupted */

      if (STDOUT_FILENO <= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }
    
    printf("%s", ind->string);
}
