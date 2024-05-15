void *sqlite3DbMallocRaw(sqlite3 *db, u64 n){
  void *p;
  if( db ) return sqlite3DbMallocRawNN(db, n);
  p = sqlite3Malloc(n);
  sqlite3MemdebugSetType(p, MEMTYPE_HEAP);
  return p;
}