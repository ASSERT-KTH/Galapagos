void db_prepare(sqlite3_stmt **pStmt, const char * zSql, ...){
  int rc;
  sqlite3_str * str = db_str_new();
  char * z = 0;
  int n = 0;
  va_list va;
  if(!str) fatal("sqlite3_str_new() failed");
  va_start(va, zSql);
  sqlite3_str_vappendf(str, zSql, va);
  va_end(va);
  rc = sqlite3_str_errcode(str);
  if(rc) fatal("sqlite3_str_errcode() = %d", rc);
  z = db_str_finish(str, &n);
  rc = sqlite3_prepare_v2(g.db, z, n, pStmt, 0);
  if(rc) fatal("Error #%d (%s) preparing: %s",
               rc, sqlite3_errmsg(g.db), z);
  sqlite3_free(z);
}