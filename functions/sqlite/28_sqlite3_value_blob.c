S3JniApi(sqlite3_value_blob(),jbyteArray,1value_1blob)(
  JniArgsEnvClass, jlong jpSVal
){
  sqlite3_value * const sv = LongPtrGet_sqlite3_value(jpSVal);
  const jbyte * pBytes = sv ? sqlite3_value_blob(sv) : 0;
  int const nLen = pBytes ? sqlite3_value_bytes(sv) : 0;

  s3jni_oom_check( nLen ? !!pBytes : 1 );
  return pBytes
    ? s3jni_new_jbyteArray(pBytes, nLen)
    : NULL;
}