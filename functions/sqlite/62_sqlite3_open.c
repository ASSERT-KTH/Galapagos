S3JniApi(sqlite3_open(),jint,1open)(
  JniArgsEnvClass, jstring strName, jobject jOut
){
  sqlite3 * pOut = 0;
  char *zName = 0;
  S3JniDb * ps = 0;
  S3JniEnv * jc = 0;
  int rc;

  if( 0==jOut ) return SQLITE_MISUSE;
  rc = s3jni_open_pre(env, &jc, strName, &zName, &ps);
  if( 0==rc ){
    rc = s3jni_open_post(env, jc, ps, &pOut, jOut,
                         sqlite3_open(zName, &pOut));
    assert(rc==0 ? pOut!=0 : 1);
    sqlite3_free(zName);
  }
  return (jint)rc;
}