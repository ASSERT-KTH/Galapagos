void *sqlite3_user_data(sqlite3_context *p){
#ifdef SQLITE_ENABLE_API_ARMOR
  if( p==0 ) return 0;
#endif
  assert( p && p->pFunc );
  return p->pFunc->pUserData;
}