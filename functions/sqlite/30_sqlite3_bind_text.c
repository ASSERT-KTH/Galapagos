int sqlite3_bind_text(
  sqlite3_stmt *pStmt,
  int i,
  const char *zData,
  int nData,
  void (*xDel)(void*)
){
  return bindText(pStmt, i, zData, nData, xDel, SQLITE_UTF8);
}