static char *fts5PrintfAppend(char *zApp, const char *zFmt, ...){
  char *zNew;
  va_list ap;
  va_start(ap, zFmt);
  zNew = sqlite3_vmprintf(zFmt, ap);
  va_end(ap);
  if( zApp && zNew ){
    char *zNew2 = sqlite3_mprintf("%s%s", zApp, zNew);
    sqlite3_free(zNew);
    zNew = zNew2;
  }
  sqlite3_free(zApp);
  return zNew;
}