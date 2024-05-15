void sqlite3BtreeLeave(Btree *p){
  assert( sqlite3_mutex_held(p->db->mutex) );
  if( p->sharable ){
    assert( p->wantToLock>0 );
    p->wantToLock--;
    if( p->wantToLock==0 ){
      unlockBtreeMutex(p);
    }
  }
}