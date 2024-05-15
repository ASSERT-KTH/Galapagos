S3JniApi(sqlite3_aggregate_context(),jlong,1aggregate_1context)(
  JniArgsEnvClass, jobject jCx, jboolean initialize
){
  sqlite3_context * const pCx = PtrGet_sqlite3_context(jCx);
  void * const p = pCx
    ? sqlite3_aggregate_context(pCx, (int)(initialize
                                           ? (int)sizeof(void*)
                                           : 0))
    : 0;
  return S3JniCast_P2L(p);
}