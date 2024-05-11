wrong_args (const char *text)
{
  es_fprintf (es_stderr, _("usage: %s [options] "), DIRMNGR_NAME);
  es_fputs (text, es_stderr);
  es_putc ('\n', es_stderr);
  dirmngr_exit (2);
}