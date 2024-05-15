S3JniApi(sqlite3_config() /* for SQLITE_CONFIG_LOG */
         sqlite3_config__config_log() /* internal name */,
         jint, 1config_1_1CONFIG_1LOG
)(JniArgsEnvClass, jobject jLog){
  S3JniHook * const pHook = &SJG.hook.configlog;
  int rc = 0;

  S3JniGlobal_mutex_enter;
  if( !jLog ){
    rc = sqlite3_config( SQLITE_CONFIG_LOG, NULL, NULL );
    if( 0==rc ){
      S3JniHook_unref(pHook);
    }
  }else if( pHook->jObj && (*env)->IsSameObject(env, jLog, pHook->jObj) ){
    /* No-op */
  }else {
    jclass const klazz = (*env)->GetObjectClass(env, jLog);
    jmethodID const midCallback = (*env)->GetMethodID(env, klazz, "call",
                                                      "(ILjava/lang/String;)V");
    S3JniUnrefLocal(klazz);
    if( midCallback ){
      rc = sqlite3_config( SQLITE_CONFIG_LOG, s3jni_config_log, NULL );
      if( 0==rc ){
        S3JniHook_unref(pHook);
        pHook->midCallback = midCallback;
        pHook->jObj = S3JniRefGlobal(jLog);
      }
    }else{
      S3JniExceptionWarnIgnore;
      rc = SQLITE_ERROR;
    }
  }
  S3JniGlobal_mutex_leave;
  return rc;
}