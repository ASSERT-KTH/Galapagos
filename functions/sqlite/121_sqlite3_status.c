S3JniApi(sqlite3_status(),jint,1status)(
  JniArgsEnvClass, jint op, jobject jOutCurrent, jobject jOutHigh,
                    jboolean reset
){
  int iCur = 0, iHigh = 0;
  int rc = sqlite3_status( op, &iCur, &iHigh, reset );
  if( 0==rc ){
    OutputPointer_set_Int32(env, jOutCurrent, iCur);
    OutputPointer_set_Int32(env, jOutHigh, iHigh);
  }
  return (jint)rc;
}