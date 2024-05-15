static CURLcode cf_progress_ingress(struct Curl_cfilter *cf,
                                    struct Curl_easy *data,
                                    struct pkt_io_ctx *pktx)
{
  struct cf_ngtcp2_ctx *ctx = cf->ctx;
  struct pkt_io_ctx local_pktx;
  size_t pkts_chunk = 128, i;
  CURLcode result = CURLE_OK;

  if(!pktx) {
    pktx_init(&local_pktx, cf, data);
    pktx = &local_pktx;
  }
  else {
    pktx_update_time(pktx, cf);
  }

  result = Curl_vquic_tls_before_recv(&ctx->tls, cf, data);
  if(result)
    return result;

  for(i = 0; i < 4; ++i) {
    if(i)
      pktx_update_time(pktx, cf);
    pktx->pkt_count = 0;
    result = vquic_recv_packets(cf, data, &ctx->q, pkts_chunk,
                                recv_pkt, pktx);
    if(result || !pktx->pkt_count) /* error or got nothing */
      break;
  }
  return result;
}