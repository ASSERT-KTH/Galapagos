Expr *sqlite3ColumnExpr(Table *pTab, Column *pCol){
  if( pCol->iDflt==0 ) return 0;
  if( !IsOrdinaryTable(pTab) ) return 0;
  if( NEVER(pTab->u.tab.pDfltList==0) ) return 0;
  if( NEVER(pTab->u.tab.pDfltList->nExpr<pCol->iDflt) ) return 0;
  return pTab->u.tab.pDfltList->a[pCol->iDflt-1].pExpr;
}