void sqlite3_result_int(sqlite3_context *pCtx, int iVal){
#ifdef SQLITE_ENABLE_API_ARMOR
  if( pCtx==0 ) return;
#endif
  assert( sqlite3_mutex_held(pCtx->pOut->db->mutex) );
  sqlite3VdbeMemSetInt64(pCtx->pOut, (i64)iVal);
}