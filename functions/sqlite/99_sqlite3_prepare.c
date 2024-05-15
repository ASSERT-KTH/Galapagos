S3JniApi(sqlite3_prepare(),jint,1prepare)(
  JNIEnv * const env, jclass self, jlong jpDb, jbyteArray baSql,
                     jint nMax, jobject jOutStmt, jobject outTail
){
  return sqlite3_jni_prepare_v123(1, env, self, jpDb, baSql, nMax, 0,
                                  jOutStmt, outTail);
}