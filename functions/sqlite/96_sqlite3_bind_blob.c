int sqlite3_bind_blob(
  sqlite3_stmt *pStmt,
  int i,
  const void *zData,
  int nData,
  void (*xDel)(void*)
){
#ifdef SQLITE_ENABLE_API_ARMOR
  if( nData<0 ) return SQLITE_MISUSE_BKPT;
#endif
  return bindText(pStmt, i, zData, nData, xDel, 0);
}