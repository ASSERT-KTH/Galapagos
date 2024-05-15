void sqlite3_result_blob(
  sqlite3_context *pCtx,
  const void *z,
  int n,
  void (*xDel)(void *)
){
#ifdef SQLITE_ENABLE_API_ARMOR
  if( pCtx==0 || n<0 ){
    invokeValueDestructor(z, xDel, pCtx);
    return;
  }
#endif
  assert( n>=0 );
  assert( sqlite3_mutex_held(pCtx->pOut->db->mutex) );
  setResultStrOrError(pCtx, z, n, 0, xDel);
}