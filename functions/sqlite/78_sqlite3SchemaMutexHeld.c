int sqlite3SchemaMutexHeld(sqlite3 *db, int iDb, Schema *pSchema){
  Btree *p;
  assert( db!=0 );
  if( db->pVfs==0 && db->nDb==0 ) return 1;
  if( pSchema ) iDb = sqlite3SchemaToIndex(db, pSchema);
  assert( iDb>=0 && iDb<db->nDb );
  if( !sqlite3_mutex_held(db->mutex) ) return 0;
  if( iDb==1 ) return 1;
  p = db->aDb[iDb].pBt;
  assert( p!=0 );
  return p->sharable==0 || p->locked==1;
}