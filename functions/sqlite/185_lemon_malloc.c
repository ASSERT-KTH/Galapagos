static void *lemon_malloc(size_t nByte){
  MemChunk *p;
  if( nByte<0 ) return 0;
  p = malloc( nByte + sizeof(MemChunk) );
  if( p==0 ){
    fprintf(stderr, "Out of memory.  Failed to allocate %lld bytes.\n",
            (long long int)nByte);
    exit(1);
  }
  p->pNext = memChunkList;
  p->sz = nByte;
  memChunkList = p;
  return (void*)&p[1];
}