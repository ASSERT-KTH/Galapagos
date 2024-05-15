static void cmdlineError(const char *zFormat, ...){
  sqlite3_str *pOut = sqlite3_str_new(0);
  va_list ap;
  va_start(ap, zFormat);
  sqlite3_str_vappendf(pOut, zFormat, ap);
  va_end(ap);
  Wfprintf(stderr, "%s: %s\n", g.zArgv0, sqlite3_str_value(pOut));
  strFree(pOut);
  Wfprintf(stderr, "\"%s --help\" for more help\n", g.zArgv0);
  exit(1);
}