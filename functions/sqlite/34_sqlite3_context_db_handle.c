S3JniApi(sqlite3_context_db_handle(),jobject,1context_1db_1handle)(
  JniArgsEnvClass, jobject jpCx
){
  sqlite3_context * const pCx = PtrGet_sqlite3_context(jpCx);
  sqlite3 * const pDb = pCx ? sqlite3_context_db_handle(pCx) : 0;
  S3JniDb * const ps = pDb ? S3JniDb_from_c(pDb) : 0;
  return ps ? ps->jDb : 0;
}