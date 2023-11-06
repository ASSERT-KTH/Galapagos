put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      /* If the standard output is a controlling terminal, then keep an 
         eye out for signals, so that the colors can be switched back to 
         their usual values if "ls" is suspended or stopped.  */
      if (STDOUT_FILENO == fileno(stdout)) 
        {  
          used_color = true;
          signal_init ();
        }
      prep_non_filename_text ();
    }

  /* Writing the string contained in ind to the standard output, providing its length */
  fputs(ind->string, stdout);
}