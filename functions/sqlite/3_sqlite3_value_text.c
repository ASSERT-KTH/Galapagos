S3JniApi(sqlite3_value_text(),jbyteArray,1value_1text)(
  JniArgsEnvClass, jlong jpSVal
){
  sqlite3_value * const sv = LongPtrGet_sqlite3_value(jpSVal);
  const unsigned char * const p = sv ? sqlite3_value_text(sv) : 0;
  int const n = p ? sqlite3_value_bytes(sv) : 0;
  return p ? s3jni_new_jbyteArray(p, n) : 0;
}