static void LZ4IO_compressChunk(void* arg)
{
    CompressJobDesc* const cjd = (CompressJobDesc*)arg;
    size_t const outCapacity = cjd->maxCBlockSize;
    void* const out_buff = malloc(outCapacity);
    if (!out_buff)
        END_PROCESS(33, "Allocation error : can't allocate output buffer to compress new chunk");
    {   char* const inBuff = (char*)cjd->buffer + cjd->prefixSize;
        size_t const cSize = cjd->compress(cjd->compressParameters, out_buff, outCapacity, inBuff, cjd->inSize, cjd->prefixSize);

        /* check for write */
        {   WriteJobDesc* const wjd = (WriteJobDesc*)malloc(sizeof(*wjd));
            if (wjd == NULL) {
                END_PROCESS(35, "Allocation error : can't describe new write job");
            }
            wjd->cBuf = out_buff;
            wjd->cSize = (size_t)cSize;
            wjd->blockNb = cjd->blockNb;
            wjd->out = cjd->fout;
            wjd->wr = cjd->wr;
            TPOOL_submitJob(cjd->wpool, LZ4IO_checkWriteOrder, wjd);
    }   }
}