cleanup(void)
{
  if (restore_termios)
    {
      restore_termios = 0; /* do it prior in case it is interrupted again */
      if (tcsetattr(fileno(ttyfp), TCSAFLUSH, &termsave))
        log_error ("tcsetattr() failed: %s\n", strerror (errno));
    }
}