void sqlite3SrcListDelete(sqlite3 *db, SrcList *pList){
  int i;
  SrcItem *pItem;
  assert( db!=0 );
  if( pList==0 ) return;
  for(pItem=pList->a, i=0; i<pList->nSrc; i++, pItem++){
    if( pItem->zDatabase ) sqlite3DbNNFreeNN(db, pItem->zDatabase);
    if( pItem->zName ) sqlite3DbNNFreeNN(db, pItem->zName);
    if( pItem->zAlias ) sqlite3DbNNFreeNN(db, pItem->zAlias);
    if( pItem->fg.isIndexedBy ) sqlite3DbFree(db, pItem->u1.zIndexedBy);
    if( pItem->fg.isTabFunc ) sqlite3ExprListDelete(db, pItem->u1.pFuncArg);
    sqlite3DeleteTable(db, pItem->pTab);
    if( pItem->pSelect ) sqlite3SelectDelete(db, pItem->pSelect);
    if( pItem->fg.isUsing ){
      sqlite3IdListDelete(db, pItem->u3.pUsing);
    }else if( pItem->u3.pOn ){
      sqlite3ExprDelete(db, pItem->u3.pOn);
    }
  }
  sqlite3DbNNFreeNN(db, pList);
}