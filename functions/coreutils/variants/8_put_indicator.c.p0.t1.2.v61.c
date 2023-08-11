put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      used_color = 1;
      
      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }

  // Check if write operation is successful
  if(fwrite (ind->string, ind->len, 1, stdout) != 1) 
  {
    // Clean up resources and reset used_color to false if write operation failed
    signal_cleanup();
    used_color = false;
    
    fprintf (stderr, "Failed to write to standard output");  
  } 
}