tty_kill_prompt (void)
{
  if (no_terminal)
    return;

  if (!initialized)
    init_ttyfp ();

  if (batchmode)
    last_prompt_len = 0;
  if (!last_prompt_len)
    return;
#ifdef HAVE_W32_SYSTEM
  tty_printf ("\r%*s\r", last_prompt_len, "");
#else /* Unix */
  {
    int i;
    putc ('\r', ttyfp);
    for (i=0; i < last_prompt_len; i ++ )
      putc (' ', ttyfp);
    putc ('\r', ttyfp);
    fflush (ttyfp);
  }
#endif /* Unix */
  last_prompt_len = 0;
}