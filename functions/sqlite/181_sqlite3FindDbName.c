int sqlite3FindDbName(sqlite3 *db, const char *zName){
  int i = -1;         /* Database number */
  if( zName ){
    Db *pDb;
    for(i=(db->nDb-1), pDb=&db->aDb[i]; i>=0; i--, pDb--){
      if( 0==sqlite3_stricmp(pDb->zDbSName, zName) ) break;
      /* "main" is always an acceptable alias for the primary database
      ** even if it has been renamed using SQLITE_DBCONFIG_MAINDBNAME. */
      if( i==0 && 0==sqlite3_stricmp("main", zName) ) break;
    }
  }
  return i;
}