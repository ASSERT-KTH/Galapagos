void helpf(FILE *errors, const char *fmt, ...)
{
  if(fmt) {
    va_list ap;
    va_start(ap, fmt);
    DEBUGASSERT(!strchr(fmt, '\n'));
    fputs("curl: ", errors); /* prefix it */
    vfprintf(errors, fmt, ap);
    va_end(ap);
    fputs("\n", errors); /* newline it */
  }
  fprintf(errors, "curl: try 'curl --help' "
#ifdef USE_MANUAL
          "or 'curl --manual' "
#endif
          "for more information\n");
}