S3JniApi(sqlite3_finalize(),jint,1finalize)(
  JniArgsEnvClass, jlong jpStmt
){
  return jpStmt
    ? sqlite3_finalize(LongPtrGet_sqlite3_stmt(jpStmt))
    : 0;
}