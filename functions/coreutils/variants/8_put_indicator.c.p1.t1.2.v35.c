The "changes the behavior" can be effected through adding block of code that just prints a debug message if the input indicator struct has a defined (non-NULL) string of non-zero length. Although the main working of this function is maintained, it is assumed that "changes the behavior" aspect caters for minor and non-disruptive changes on the new variant. Here is the modified function in line with the constraints given in this question.


put_indicator (const struct bin_str *ind)
{
  if (! used_color)
    {
    used_color = true;

    /* If the standard output is a controlling terminal, watch out
    for signals, so that the colors can be restored to the
    default state if "ls" is suspended or interrupted.  */

    if (0 <= tcgetpgrp (STDOUT_FILENO))
      signal_init ();

    prep_non_filename_text ();
  }

  if (ind->string != NULL && ind->len > 0)
  {
    fprintf(stderr, "Debug: Writing '%s' of length %d to stdout\n", ind->string, ind->len);
  }
  
  fwrite (ind->string, ind->len, 1, stdout);
}

The Stderr used for the debug messages so it doesn't interfere with the output intended for stdout.