bool Curl_host_is_ipnum(const char *hostname)
{
  struct in_addr in;
#ifdef USE_IPV6
  struct in6_addr in6;
#endif
  if(Curl_inet_pton(AF_INET, hostname, &in) > 0
#ifdef USE_IPV6
     || Curl_inet_pton(AF_INET6, hostname, &in6) > 0
#endif
    )
    return TRUE;
  return FALSE;
}