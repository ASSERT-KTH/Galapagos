static void strPrintfArray(
  sqlite3_str *pStr,              /* String object to append to */
  const char *zSep,               /* Separator string */
  const char *zFmt,               /* Format for each entry */
  char **az, int n                /* Array of strings & its size (or -1) */
){
  int i;
  for(i=0; az[i] && (i<n || n<0); i++){
    if( i!=0 ) sqlite3_str_appendf(pStr, "%s", zSep);
    sqlite3_str_appendf(pStr, zFmt, az[i], az[i], az[i]);
  }
}