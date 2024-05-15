static void LZ4F_freeReadFile(LZ4_readFile_t* lz4fRead)
{
  if (lz4fRead==NULL) return;
  LZ4F_freeDecompressionContext(lz4fRead->dctxPtr);
  free(lz4fRead->srcBuf);
  free(lz4fRead);
}