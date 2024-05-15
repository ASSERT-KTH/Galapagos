i16 sqlite3TableColumnToStorage(Table *pTab, i16 iCol){
  int i;
  i16 n;
  assert( iCol<pTab->nCol );
  if( (pTab->tabFlags & TF_HasVirtual)==0 || iCol<0 ) return iCol;
  for(i=0, n=0; i<iCol; i++){
    if( (pTab->aCol[i].colFlags & COLFLAG_VIRTUAL)==0 ) n++;
  }
  if( pTab->aCol[i].colFlags & COLFLAG_VIRTUAL ){
    /* iCol is a virtual column itself */
    return pTab->nNVCol + i - n;
  }else{
    /* iCol is a normal or stored column */
    return n;
  }
}