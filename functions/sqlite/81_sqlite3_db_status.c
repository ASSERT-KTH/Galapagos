S3JniApi(sqlite3_db_status(),jint,1db_1status)(
  JniArgsEnvClass, jobject jDb, jint op, jobject jOutCurrent,
                        jobject jOutHigh, jboolean reset
){
  int iCur = 0, iHigh = 0;
  sqlite3 * const pDb = PtrGet_sqlite3(jDb);
  int rc = sqlite3_db_status( pDb, op, &iCur, &iHigh, reset );
  if( 0==rc ){
    OutputPointer_set_Int32(env, jOutCurrent, iCur);
    OutputPointer_set_Int32(env, jOutHigh, iHigh);
  }
  return (jint)rc;
}