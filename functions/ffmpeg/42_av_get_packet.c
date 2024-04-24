int av_get_packet(AVIOContext *s, AVPacket *pkt, int size)
{
#if FF_API_INIT_PACKET
FF_DISABLE_DEPRECATION_WARNINGS
    av_init_packet(pkt);
    pkt->data = NULL;
    pkt->size = 0;
FF_ENABLE_DEPRECATION_WARNINGS
#else
    av_packet_unref(pkt);
#endif
    pkt->pos  = avio_tell(s);

    return append_packet_chunked(s, pkt, size);
}