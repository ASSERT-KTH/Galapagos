void sqlite3_result_text(
  sqlite3_context *pCtx,
  const char *z,
  int n,
  void (*xDel)(void *)
){
#ifdef SQLITE_ENABLE_API_ARMOR
  if( pCtx==0 ){
    invokeValueDestructor(z, xDel, 0);
    return;
  }
#endif
  assert( sqlite3_mutex_held(pCtx->pOut->db->mutex) );
  setResultStrOrError(pCtx, z, n, SQLITE_UTF8, xDel);
}