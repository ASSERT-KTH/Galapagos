void *sqlite3DbRealloc(sqlite3 *db, void *p, u64 n){
  assert( db!=0 );
  if( p==0 ) return sqlite3DbMallocRawNN(db, n);
  assert( sqlite3_mutex_held(db->mutex) );
  if( ((uptr)p)<(uptr)db->lookaside.pEnd ){
#ifndef SQLITE_OMIT_TWOSIZE_LOOKASIDE
    if( ((uptr)p)>=(uptr)db->lookaside.pMiddle ){
      if( n<=LOOKASIDE_SMALL ) return p;
    }else
#endif
    if( ((uptr)p)>=(uptr)db->lookaside.pStart ){
      if( n<=db->lookaside.szTrue ) return p;
    }
  }
  return dbReallocFinish(db, p, n);
}