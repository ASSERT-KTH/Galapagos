bool Curl_ipv6works(struct Curl_easy *data)
{
  if(data) {
    /* the nature of most system is that IPv6 status doesn't come and go
       during a program's lifetime so we only probe the first time and then we
       have the info kept for fast reuse */
    DEBUGASSERT(data);
    DEBUGASSERT(data->multi);
    if(data->multi->ipv6_up == IPV6_UNKNOWN) {
      bool works = Curl_ipv6works(NULL);
      data->multi->ipv6_up = works ? IPV6_WORKS : IPV6_DEAD;
    }
    return data->multi->ipv6_up == IPV6_WORKS;
  }
  else {
    int ipv6_works = -1;
    /* probe to see if we have a working IPv6 stack */
    curl_socket_t s = socket(PF_INET6, SOCK_DGRAM, 0);
    if(s == CURL_SOCKET_BAD)
      /* an IPv6 address was requested but we can't get/use one */
      ipv6_works = 0;
    else {
      ipv6_works = 1;
      sclose(s);
    }
    return (ipv6_works>0)?TRUE:FALSE;
  }
}