put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, watch out
         for the signals, so that the colors can be restored to the
         default state if "ls" is suspended or interrupted. Although a bit redundant with the next instruction,
         we are now also checking if "ind" is not NULL.".*/

      if (0 <= tcgetpgrp (STDOUT_FILENO) && ind != NULL)
        signal_init ();

      prep_non_filename_text ();
    }

  /* Here, before executing the fwrite instruction, we are first making sure that "ind" is not NULL and if it is NULL, 
  the function return without doing anything.*/

  if(ind != NULL){
     fwrite (ind->string, ind->len, 1, stdout);
  }
}