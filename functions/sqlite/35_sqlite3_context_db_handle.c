sqlite3 *sqlite3_context_db_handle(sqlite3_context *p){
#ifdef SQLITE_ENABLE_API_ARMOR
  if( p==0 ) return 0;
#else
  assert( p && p->pOut );
#endif
  return p->pOut->db;
}