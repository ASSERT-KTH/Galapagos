S3JniApi(sqlite3_column_text(),jbyteArray,1column_1text)(
  JniArgsEnvClass, jobject jpStmt, jint ndx
){
  sqlite3_stmt * const stmt = PtrGet_sqlite3_stmt(jpStmt);
  const unsigned char * const p = stmt ? sqlite3_column_text(stmt, (int)ndx) : 0;
  const int n = p ? sqlite3_column_bytes(stmt, (int)ndx) : 0;
  return p ? s3jni_new_jbyteArray(p, n) : NULL;
}