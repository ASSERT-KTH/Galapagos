void avio_wb32(AVIOContext *s, unsigned int val)
{
    s->pb.buffer[0] = (val & 0xff000000) >> 24;
    s->pb.buffer[1] = (val & 0x00ff0000) >> 16;
    s->pb.buffer[2] = (val & 0x0000ff00) >> 8;
    s->pb.buffer[3] = (val & 0x000000ff);
}