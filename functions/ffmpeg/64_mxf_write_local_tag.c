static void mxf_write_local_tag(AVFormatContext *s, int size, int tag)
{
    MXFContext *mxf = s->priv_data;
    AVIOContext *pb = s->pb;
    const MXFLocalTagPair *pair = mxf_lookup_local_tag(tag);

    // make sure the tag was not declared unnecessary upfront
    av_assert0(mxf->unused_tags[pair - mxf_local_tag_batch] == 0);

    avio_wb16(pb, tag);
    avio_wb16(pb, size);
}