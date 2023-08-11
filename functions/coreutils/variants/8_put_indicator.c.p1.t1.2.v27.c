void put_indicator (const struct bin_str *ind)
{
  static int initialize = 0; 

  if (initialize == 0)
    {
      initialize = 1; // Signals that initialization has been done.
      
      /* This if statement checks if the output destination is a terminal. 
         If it is, it prepares to receive signals, so that if the output is
         interrupted, it can reset to its default state. */
      if (0 <= tcgetpgrp (STDOUT_FILENO)) 
        signal_init ();

      // A small preparation phase for non file name text.
      prep_non_filename_text (); 
    }

  /* The characters in the string as well as a single character denoting
     the length are being written into the standard output file. */
  fwrite (ind->string, ind->len, 1, stdout); 
}