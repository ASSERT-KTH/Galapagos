wrong_args (const char *text, const char *text2)
{
#if GPGRT_VERSION_NUMBER >= 0x013000 /* >= 1.48 */
  /* Skip the leading dashes if build with command support.  */
  if (text[0] == '-' && text[1] == '-' && text[2])
    text += 2;
#endif
  es_fprintf (es_stderr, _("usage: %s %s [options] %s\n"),
              gpgrt_strusage (11), text, text2);
  exit (2);
}