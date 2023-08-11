put_indicator_modified (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = true;

      /* An altered version maintains watching out for signals for restoring colors. */
      if (STDOUT_FILENO >= tcgetpgrp (0))
        signal_init ();

      prep_non_filename_text ();
    }
 
  /* Check if string from 'ind' parameter is not a NULL pointer before using fwrite function. */  
  if (ind->string != NULL) 
    fwrite (ind->string, ind->len, 1, stdout); 
  else 
    printf("String is not provided\n");


}