int sqlite3SafetyCheckOk(sqlite3 *db){
  u8 eOpenState;
  if( db==0 ){
    logBadConnection("NULL");
    return 0;
  }
  eOpenState = db->eOpenState;
  if( eOpenState!=SQLITE_STATE_OPEN ){
    if( sqlite3SafetyCheckSickOrOk(db) ){
      testcase( sqlite3GlobalConfig.xLog!=0 );
      logBadConnection("unopened");
    }
    return 0;
  }else{
    return 1;
  }
}