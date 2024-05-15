S3JniApi(sqlite3_column_value(),jobject,1column_1value)(
  JniArgsEnvClass, jobject jpStmt, jint ndx
){
  sqlite3_value * const sv =
    sqlite3_column_value(PtrGet_sqlite3_stmt(jpStmt), (int)ndx)
    /* reminder: returns an SQL NULL if jpStmt==NULL */;
  return new_java_sqlite3_value(env, sv);
}