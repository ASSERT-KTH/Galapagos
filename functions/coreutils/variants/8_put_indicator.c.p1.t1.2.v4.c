void put_indicator (const struct bin_str *ind)
{
  static bool init_done = false;

  if (!init_done)
  {
    init_done = true;
    used_color = true;

    if (0 <= tcgetpgrp (STDOUT_FILENO))
      signal_init ();

    prep_non_filename_text ();
  }

  if(used_color)
  {
    fwrite (ind->string, ind->len, 1, stdout);
  }
}
This is a slightly different approach, but essentially carries out the same operations. Instead of directly asking if used_color is false, we use a static boolean variable to make sure the initialization (for lack of a better term) commands are only executed once. This achieves the same purpose but has the benefit of allowing used_color to be used or altered elsewhere in the program without affecting our indicator function.
Only if used_color is true, it writes in stdout, otherwise does nothing. It's a subtle change, but a change still!