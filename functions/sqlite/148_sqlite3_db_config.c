S3JniApi(sqlite3_db_config() /*for MAINDBNAME*/,
         jint,1db_1config__Lorg_sqlite_jni_capi_sqlite3_2ILjava_lang_String_2
)(JniArgsEnvClass, jobject jDb, jint op, jstring jStr){
  S3JniDb * const ps = S3JniDb_from_java(jDb);
  int rc;
  char *zStr;

  switch( (ps && jStr) ? op : 0 ){
    case SQLITE_DBCONFIG_MAINDBNAME:
      S3JniDb_mutex_enter
        /* Protect against a race in modifying/freeing
           ps->zMainDbName. */;
      zStr = s3jni_jstring_to_utf8( jStr, 0);
      if( zStr ){
        rc = sqlite3_db_config(ps->pDb, (int)op, zStr);
        if( rc ){
          sqlite3_free( zStr );
        }else{
          sqlite3_free( ps->zMainDbName );
          ps->zMainDbName = zStr;
        }
      }else{
        rc = SQLITE_NOMEM;
      }
      S3JniDb_mutex_leave;
      break;
    case 0:
    default:
      rc = SQLITE_MISUSE;
  }
  return rc;
}