char *sqlite3NameFromToken(sqlite3 *db, const Token *pName){
  char *zName;
  if( pName ){
    zName = sqlite3DbStrNDup(db, (const char*)pName->z, pName->n);
    sqlite3Dequote(zName);
  }else{
    zName = 0;
  }
  return zName;
}