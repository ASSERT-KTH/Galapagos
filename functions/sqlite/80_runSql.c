static void runSql(sqlite3 *db, const char *zSql){
  char *zErr = 0;
  int rc;
  nReply = 0;
  rc = sqlite3_exec(db, zSql, execCallback, 0, &zErr);
  if( zErr ){
    fprintf(stderr, "SQL error: %s\n", zErr);
    exit(1);
  }
  if( rc ){
    fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    exit(1);
  }
}