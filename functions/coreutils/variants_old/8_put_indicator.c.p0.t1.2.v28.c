put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted. We also prep non-filename text here*/

      if (0 <= tcgetpgrp (STDOUT_FILENO))
        {
          signal_init ();
          prep_non_filename_text ();
        }
    }
    
  /* Writing to standard output block by block, after standard output configured correctly.*/
  size_t i =0;
  for(i = 0; i < ind->len; i++)
  {
    fwrite ((ind->string)+i, 1, 1, stdout);
  }
}