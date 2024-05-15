static void sqlite3TreeViewPop(TreeView **pp){
  TreeView *p = *pp;
  if( p==0 ) return;
  p->iLevel--;
  if( p->iLevel<0 ){
    sqlite3_free(p);
    *pp = 0;
  }
}