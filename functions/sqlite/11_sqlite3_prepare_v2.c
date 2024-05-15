S3JniApi(sqlite3_prepare_v2(),jint,1prepare_1v2)(
  JNIEnv * const env, jclass self, jlong jpDb, jbyteArray baSql,
                         jint nMax, jobject jOutStmt, jobject outTail
){
  return sqlite3_jni_prepare_v123(2, env, self, jpDb, baSql, nMax, 0,
                                  jOutStmt, outTail);
}