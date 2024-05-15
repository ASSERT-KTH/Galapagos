S3JniApi(sqlite3_bind_blob(),jint,1bind_1blob)(
  JniArgsEnvClass, jlong jpStmt, jint ndx, jbyteArray baData, jint nMax
){
  jsize nBA = 0;
  jbyte * const pBuf = baData ? s3jni_jbyteArray_bytes2(baData, &nBA) : 0;
  int rc;
  if( pBuf ){
    if( nMax>nBA ){
      nMax = nBA;
    }
    rc = sqlite3_bind_blob(LongPtrGet_sqlite3_stmt(jpStmt), (int)ndx,
                           pBuf, (int)nMax, SQLITE_TRANSIENT);
    s3jni_jbyteArray_release(baData, pBuf);
  }else{
    rc = baData
      ? SQLITE_NOMEM
      : sqlite3_bind_null( LongPtrGet_sqlite3_stmt(jpStmt), ndx );
  }
  return (jint)rc;
}