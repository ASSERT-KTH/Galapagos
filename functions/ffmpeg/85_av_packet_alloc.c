AVPacket *av_packet_alloc(void)
{
    AVPacket *pkt = av_malloc(sizeof(AVPacket));
    if (!pkt)
        return pkt;

    get_packet_defaults(pkt);

    return pkt;
}