static av_always_inline int bytestream2_seek(GetByteContext *g,
                                             int offset,
                                             int whence)
{
    switch (whence) {
    case SEEK_CUR:
        offset     = av_clip(offset, -(g->buffer - g->buffer_start),
                             g->buffer_end - g->buffer);
        g->buffer += offset;
        break;
    case SEEK_END:
        offset    = av_clip(offset, -(g->buffer_end - g->buffer_start), 0);
        g->buffer = g->buffer_end + offset;
        break;
    case SEEK_SET:
        offset    = av_clip(offset, 0, g->buffer_end - g->buffer_start);
        g->buffer = g->buffer_start + offset;
        break;
    default:
        return AVERROR(EINVAL);
    }
    return bytestream2_tell(g);
}