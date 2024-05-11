dirmngr_use_tor (void)
{
  if (tor_mode == TOR_MODE_AUTO)
    {
      /* Figure out whether Tor is running.  */
      assuan_fd_t sock;

      sock = assuan_sock_connect_byname (NULL, 0, 0, NULL, ASSUAN_SOCK_TOR);
      if (sock == ASSUAN_INVALID_FD)
        tor_mode = TOR_MODE_NO;
      else
        {
          tor_mode = TOR_MODE_YES;
          assuan_sock_close (sock);
        }
    }

  if (tor_mode == TOR_MODE_FORCE)
    return 2; /* Use Tor (using 2 to indicate force mode) */
  else if (tor_mode == TOR_MODE_YES)
    return 1; /* Use Tor */
  else
    return 0; /* Do not use Tor.  */
}