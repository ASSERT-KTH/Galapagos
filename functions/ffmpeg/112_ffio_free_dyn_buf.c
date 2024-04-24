void ffio_free_dyn_buf(AVIOContext **s)
{
    DynBuffer *d;

    if (!*s)
        return;

    d = (*s)->opaque;
    av_free(d->buffer);
    avio_context_free(s);
}