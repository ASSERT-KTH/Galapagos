void sqlite3NestedParse(Parse *pParse, const char *zFormat, ...){
  va_list ap;
  char *zSql;
  sqlite3 *db = pParse->db;
  u32 savedDbFlags = db->mDbFlags;
  char saveBuf[PARSE_TAIL_SZ];

  if( pParse->nErr ) return;
  if( pParse->eParseMode ) return;
  assert( pParse->nested<10 );  /* Nesting should only be of limited depth */
  va_start(ap, zFormat);
  zSql = sqlite3VMPrintf(db, zFormat, ap);
  va_end(ap);
  if( zSql==0 ){
    /* This can result either from an OOM or because the formatted string
    ** exceeds SQLITE_LIMIT_LENGTH.  In the latter case, we need to set
    ** an error */
    if( !db->mallocFailed ) pParse->rc = SQLITE_TOOBIG;
    pParse->nErr++;
    return;
  }
  pParse->nested++;
  memcpy(saveBuf, PARSE_TAIL(pParse), PARSE_TAIL_SZ);
  memset(PARSE_TAIL(pParse), 0, PARSE_TAIL_SZ);
  db->mDbFlags |= DBFLAG_PreferBuiltin;
  sqlite3RunParser(pParse, zSql);
  db->mDbFlags = savedDbFlags;
  sqlite3DbFree(db, zSql);
  memcpy(PARSE_TAIL(pParse), saveBuf, PARSE_TAIL_SZ);
  pParse->nested--;
}