cleanup (void)
{
  crl_cache_deinit ();
  cert_cache_deinit (1);
  reload_dns_stuff (1);

#if USE_LDAP
  ldapserver_list_free (opt.ldapservers);
#endif /*USE_LDAP*/
  opt.ldapservers = NULL;

  if (cleanup_socket)
    {
      cleanup_socket = 0;
      if (redir_socket_name)
        gnupg_remove (redir_socket_name);
      else if (socket_name && *socket_name)
        gnupg_remove (socket_name);
    }
}