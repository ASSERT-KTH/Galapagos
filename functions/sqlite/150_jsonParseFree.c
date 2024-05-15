static void jsonParseFree(JsonParse *pParse){
  if( pParse ){
    if( pParse->nJPRef>1 ){
      pParse->nJPRef--;
    }else{
      jsonParseReset(pParse);
      sqlite3DbFree(pParse->db, pParse);
    }
  }
}