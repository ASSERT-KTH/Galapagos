static int fsPageToBlock(FileSystem *pFS, LsmPgno iPg){
  if( pFS->pCompress ){
    return (int)((iPg / pFS->nBlocksize) + 1);
  }else{
    return (int)(1 + ((iPg-1) / (pFS->nBlocksize / pFS->nPagesize)));
  }
}