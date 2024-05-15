S3JniApi(sqlite3_column_blob(),jbyteArray,1column_1blob)(
  JniArgsEnvClass, jobject jpStmt, jint ndx
){
  sqlite3_stmt * const pStmt = PtrGet_sqlite3_stmt(jpStmt);
  void const * const p = sqlite3_column_blob(pStmt, (int)ndx);
  int const n = p ? sqlite3_column_bytes(pStmt, (int)ndx) : 0;

  return p ? s3jni_new_jbyteArray(p, n) : 0;
}