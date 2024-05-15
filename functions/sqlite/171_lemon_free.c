static void lemon_free(void *pOld){
  if( pOld ){
    MemChunk *p = (MemChunk*)pOld;
    p--;
    memset(pOld, 0, p->sz);
  }
}