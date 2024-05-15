void sqlite3DeleteTable(sqlite3 *db, Table *pTable){
  /* Do not delete the table until the reference count reaches zero. */
  assert( db!=0 );
  if( !pTable ) return;
  if( db->pnBytesFreed==0 && (--pTable->nTabRef)>0 ) return;
  deleteTable(db, pTable);
}