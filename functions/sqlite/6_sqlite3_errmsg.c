S3JniApi(sqlite3_errmsg(),jstring,1errmsg)(
  JniArgsEnvClass, jobject jpDb
){
  sqlite3 * const pDb = PtrGet_sqlite3(jpDb);
  return pDb ? s3jni_utf8_to_jstring( sqlite3_errmsg(pDb), -1) : 0
    /* We don't use errmsg16() directly only because it would cause an
       additional level of internal encoding in sqlite3. The end
       effect should be identical to using errmsg16(), however. */;
}