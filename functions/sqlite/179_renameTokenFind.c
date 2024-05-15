static RenameToken *renameTokenFind(
  Parse *pParse,
  struct RenameCtx *pCtx,
  const void *pPtr
){
  RenameToken **pp;
  if( NEVER(pPtr==0) ){
    return 0;
  }
  for(pp=&pParse->pRename; (*pp); pp=&(*pp)->pNext){
    if( (*pp)->p==pPtr ){
      RenameToken *pToken = *pp;
      if( pCtx ){
        *pp = pToken->pNext;
        pToken->pNext = pCtx->pList;
        pCtx->pList = pToken;
        pCtx->nList++;
      }
      return pToken;
    }
  }
  return 0;
}