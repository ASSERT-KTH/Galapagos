int sqlite3ExprVectorSize(const Expr *pExpr){
  u8 op = pExpr->op;
  if( op==TK_REGISTER ) op = pExpr->op2;
  if( op==TK_VECTOR ){
    assert( ExprUseXList(pExpr) );
    return pExpr->x.pList->nExpr;
  }else if( op==TK_SELECT ){
    assert( ExprUseXSelect(pExpr) );
    return pExpr->x.pSelect->pEList->nExpr;
  }else{
    return 1;
  }
}