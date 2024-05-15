static int runSql(sqlite3 *db, const char *zFormat, ...){
  va_list ap;
  char *zSql;
  int rc;

  va_start(ap, zFormat);
  zSql = sqlite3_vmprintf(zFormat, ap);
  rc = sqlite3_exec(db, zSql, 0, 0, 0);
  va_end(ap);
  return rc;
}