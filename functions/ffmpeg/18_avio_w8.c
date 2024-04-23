void avio_w8(AVIOContext *s, int b)
{
    av_assert2(b>=-128 && b<=255);
    *s->buf_ptr++ = b;
    if (s->buf_ptr >= s->buf_end)
        flush_buffer(s);
}