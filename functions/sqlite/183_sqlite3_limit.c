S3JniApi(sqlite3_limit(),jint,1limit)(
  JniArgsEnvClass, jobject jpDb, jint id, jint newVal
){
  jint rc = 0;
  sqlite3 * const pDb = PtrGet_sqlite3(jpDb);
  if( pDb ){
    rc = sqlite3_limit( pDb, (int)id, (int)newVal );
  }
  return rc;
}