void av_packet_unref(AVPacket *pkt)
{
    av_packet_free_side_data(pkt);
    av_buffer_unref(&pkt->opaque_ref);
    av_buffer_unref(&pkt->buf);
    get_packet_defaults(pkt);
}