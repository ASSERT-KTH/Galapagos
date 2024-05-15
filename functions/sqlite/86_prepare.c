static sqlite3_stmt *prepare(sqlite3 *db, const char *zFormat, ...){
  va_list ap;
  char *zSql;
  sqlite3_stmt *pStmt;
  int rc;

  va_start(ap, zFormat);
  zSql = sqlite3_vmprintf(zFormat, ap);
  va_end(ap);
  rc = sqlite3_prepare_v2(db, zSql, -1, &pStmt, 0);
  if( rc ){
    fprintf(stderr, "Error: %s\nSQL: %s\n", sqlite3_errmsg(db), zSql);
    exit(1);
  }
  sqlite3_free(zSql);
  return pStmt;
}