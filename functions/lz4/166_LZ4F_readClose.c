LZ4F_errorCode_t LZ4F_readClose(LZ4_readFile_t* lz4fRead)
{
  if (lz4fRead == NULL)
    RETURN_ERROR(parameter_null);
  LZ4F_freeReadFile(lz4fRead);
  return LZ4F_OK_NoError;
}