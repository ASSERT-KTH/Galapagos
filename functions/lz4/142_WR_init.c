static WriteRegister WR_init(size_t blockSize)
{
    WriteRegister wr = { 0, NULL, WR_INITIAL_BUFFER_POOL_SIZE, 0, 0 };
    wr.buffers = (BufferDesc*)calloc(1, WR_INITIAL_BUFFER_POOL_SIZE * sizeof(BufferDesc));
    wr.blockSize = blockSize;
    return wr;
}