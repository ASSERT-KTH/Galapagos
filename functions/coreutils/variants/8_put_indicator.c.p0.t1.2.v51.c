put_indicator(const struct bin_str *ind)
{
   if (!used_color)
   {
       used_color = true;

       /* Adjusted to run a check if output goes to a terminal */
       /* then provide signal handling to restore default colors. */

       if (isatty(STDOUT_FILENO))
       {
          signal_init();
          prep_non_filename_text ();
       }
     }

    /* Decided to use write instead of fwrite */
    write(STDOUT_FILENO, ind->string, ind->len);
}