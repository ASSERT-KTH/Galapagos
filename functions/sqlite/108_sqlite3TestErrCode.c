int sqlite3TestErrCode(Tcl_Interp *interp, sqlite3 *db, int rc){
  if( sqlite3_threadsafe()==0 && rc!=SQLITE_MISUSE && rc!=SQLITE_OK
   && sqlite3_errcode(db)!=rc ){
    char zBuf[200];
    int r2 = sqlite3_errcode(db);
    sqlite3_snprintf(sizeof(zBuf), zBuf,
       "error code %s (%d) does not match sqlite3_errcode %s (%d)",
       t1ErrorName(rc), rc, t1ErrorName(r2), r2);
    Tcl_ResetResult(interp);
    Tcl_AppendResult(interp, zBuf, 0);
    return 1;
  }
  return 0;
}