static void update_size(AVIOContext *out, int64_t pos)
{
    int64_t end = avio_tell(out);
    avio_seek(out, pos, SEEK_SET);
    avio_wb32(out, end - pos);
    avio_seek(out, end, SEEK_SET);
}