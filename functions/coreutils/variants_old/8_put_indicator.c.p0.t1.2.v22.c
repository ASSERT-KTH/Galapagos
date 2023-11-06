put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* If the standard output is a controlling terminal, check for signals,
         thereby the colors can be restored to the original state if 'ls' is interrupted
         or suspended.  */
        
      int pgrp_check = tcgetpgrp (STDOUT_FILENO);
      if(pgrp_check >= 0)
        {
          signal_init ();
        }

      prep_non_filename_text ();
    }

  if(ind != NULL){
    fwrite (ind->string, ind->len, 1, stdout);
}
  else{
    return;
  }
}