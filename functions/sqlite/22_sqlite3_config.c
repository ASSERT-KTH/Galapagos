S3JniApi(sqlite3_config() /*for a small subset of options.*/
         sqlite3_config__enable()/* internal name to avoid name-mangling issues*/,
         jint,1config_1_1enable)(JniArgsEnvClass, jint n){
  switch( n ){
    case SQLITE_CONFIG_SINGLETHREAD:
    case SQLITE_CONFIG_MULTITHREAD:
    case SQLITE_CONFIG_SERIALIZED:
      return sqlite3_config( n );
    default:
      return SQLITE_MISUSE;
  }
}