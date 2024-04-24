static av_always_inline void bytestream2_init(GetByteContext *g,
                                              const uint8_t *buf,
                                              int buf_size)
{
    av_assert0(buf_size >= 0);
    g->buffer       = buf;
    g->buffer_start = buf;
    g->buffer_end   = buf + buf_size;
}