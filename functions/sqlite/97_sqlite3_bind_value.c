S3JniApi(sqlite3_bind_value(),jint,1bind_1value)(
  JniArgsEnvClass, jlong jpStmt, jint ndx, jlong jpValue
){
  int rc = 0;
  sqlite3_stmt * pStmt = LongPtrGet_sqlite3_stmt(jpStmt);
  if( pStmt ){
    sqlite3_value *v = LongPtrGet_sqlite3_value(jpValue);
    if( v ){
      rc = sqlite3_bind_value(pStmt, (int)ndx, v);
    }else{
      rc = sqlite3_bind_null(pStmt, (int)ndx);
    }
  }else{
    rc = SQLITE_MISUSE;
  }
  return (jint)rc;
}