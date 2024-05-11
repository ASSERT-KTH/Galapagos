wrong_args (const char *text)
{
  fprintf (stderr, _("usage: %s [options] "), G13_NAME);
  fputs (text, stderr);
  putc ('\n', stderr);
  g13_exit (2);
}