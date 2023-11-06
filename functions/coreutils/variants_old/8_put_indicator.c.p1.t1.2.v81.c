void put_indicator (const struct bin_str *ind)
{
  if (! used_color)
  {
    used_color = true;
      
    // Changes made: Convert some portion of code to ternary operator
    (0 <= tcgetpgrp (STDOUT_FILENO)) ? signal_init() : NULL ;
      
    prep_non_filename_text();
  }
    
  // Changes made: Checking if fwrite was successful
  size_t num_elements_written = fwrite(ind->string, ind->len, 1, stdout);
   
  if (num_elements_written < 1)
  {
    // Handle fwrite error, for example for the function to fail silently you might put a return here.
    // Currently it does not alter overall function behavior apart from error-checking
  }
}