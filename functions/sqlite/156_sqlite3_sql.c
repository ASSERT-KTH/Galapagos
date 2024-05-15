S3JniApi(sqlite3_sql(),jstring,1sql)(
  JniArgsEnvClass, jobject jpStmt
){
  sqlite3_stmt * const pStmt = PtrGet_sqlite3_stmt(jpStmt);
  jstring rv = 0;
  if( pStmt ){
    const char * zSql = 0;
    zSql = sqlite3_sql(pStmt);
    rv = s3jni_utf8_to_jstring( zSql, -1);
  }
  return rv;
}