static void oldap_state(struct Curl_easy *data, ldapstate newstate)
{
  struct ldapconninfo *ldapc = data->conn->proto.ldapc;

#if defined(DEBUGBUILD) && !defined(CURL_DISABLE_VERBOSE_STRINGS)
  /* for debug purposes */
  static const char * const names[] = {
    "STOP",
    "SSL",
    "STARTTLS",
    "TLS",
    "MECHS",
    "SASL",
    "BIND",
    "BINDV2",
    /* LAST */
  };

  if(ldapc->state != newstate)
    infof(data, "LDAP %p state change from %s to %s",
          (void *)ldapc, names[ldapc->state], names[newstate]);
#endif

  ldapc->state = newstate;
}