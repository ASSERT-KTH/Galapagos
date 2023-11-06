put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
      /*Activate color and prepare non file name text using ls*/
      used_color = true;

      /*When standard output is the controlling terminal, the signal_init function is intended to
        ensure that if ls is interrupted or suspended, colors will be reset back to the default state.*/
      if (tcgetpgrp (STDOUT_FILENO) >= 0)
        signal_init ();

      prep_non_filename_text ();
    }
  
  /*Write the indicator information through fwrite directly to the stdout, length is calculated during write*/
  fwrite (ind->string, strlen(ind->string), 1, stdout);
} 

Note : Given modification will give same behavior as original, provided ind->len is set properly while initializing ind. Here instead of using provided ind->len, strlen(ind->string) is used which gives indicator string length dynamically. But it is based on null character termination of string. Auxiliary functionality of init_signal and prep_non_filename_text is not affected with this modification, and it still maintains its original functionality.