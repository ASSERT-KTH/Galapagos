int sqlite3BtreeHoldsMutex(Btree *p){
  assert( p->sharable==0 || p->locked==0 || p->wantToLock>0 );
  assert( p->sharable==0 || p->locked==0 || p->db==p->pBt->db );
  assert( p->sharable==0 || p->locked==0 || sqlite3_mutex_held(p->pBt->mutex) );
  assert( p->sharable==0 || p->locked==0 || sqlite3_mutex_held(p->db->mutex) );

  return (p->sharable==0 || p->locked);
}