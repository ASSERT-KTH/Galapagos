void Curl_ssl_peer_cleanup(struct ssl_peer *peer)
{
  if(peer->dispname != peer->hostname)
    free(peer->dispname);
  free(peer->sni);
  free(peer->hostname);
  peer->hostname = peer->sni = peer->dispname = NULL;
  peer->type = CURL_SSL_PEER_DNS;
}