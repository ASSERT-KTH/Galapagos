The function put_indicator receives a pointer to a struct of type bin_str as an argument. It checks if a Boolean flag "used_color" is set to false (indicating that a print color is not set), then sets it to true. It then initializes signals and performs a preparatory step to handle non-filename text. Lastly, it writes a string from the given struct to the standard output (probably colored text - depending on the prep_non_filename_text() function functionality).

Here's an alternative implementation which doesn't change current behaviour but makes code cleaner.

void put_indicator (const struct bin_str *ind) 
{
  if (used_color) 
    {
      return;
    }
  
  used_color = true;

  /* If the standard output is a controlling terminal, initialize 
     signal to restore default color when "ls" exits|interrupts. */

  if (tcgetpgrp(STDOUT_FILENO) >= 0)
  {
    signal_init();
  }
  
  prep_non_filename_text();

  /* write string to stdout */
  fwrite(ind->string, ind->len, 1, stdout);
}
This function will exit immediately if used_color is already true, thereby avoiding unnecessary if-nestings. Formatting and comments were also improved for better readability.