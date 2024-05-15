S3JniApi(sqlite3_open_v2(),jint,1open_1v2)(
  JniArgsEnvClass, jstring strName,
  jobject jOut, jint flags, jstring strVfs
){
  sqlite3 * pOut = 0;
  char *zName = 0;
  S3JniDb * ps = 0;
  S3JniEnv * jc = 0;
  char *zVfs = 0;
  int rc;

  if( 0==jOut ) return SQLITE_MISUSE;
  rc = s3jni_open_pre(env, &jc, strName, &zName, &ps);
  if( 0==rc ){
    if( strVfs ){
      zVfs = s3jni_jstring_to_utf8( strVfs, 0);
      if( !zVfs ){
        rc = SQLITE_NOMEM;
      }
    }
    if( 0==rc ){
      rc = sqlite3_open_v2(zName, &pOut, (int)flags, zVfs);
    }
    rc = s3jni_open_post(env, jc, ps, &pOut, jOut, rc);
  }
  assert(rc==0 ? pOut!=0 : 1);
  sqlite3_free(zName);
  sqlite3_free(zVfs);
  return (jint)rc;
}