cleanup (void)
{
  static int done;

  if (done)
    return;
  done = 1;
  deinitialize_module_cache ();
  if (!is_supervised && !inhibit_socket_removal)
    {
      remove_socket (socket_name, redir_socket_name);
      if (opt.extra_socket > 1)
        remove_socket (socket_name_extra, redir_socket_name_extra);
      if (opt.browser_socket > 1)
        remove_socket (socket_name_browser, redir_socket_name_browser);
      remove_socket (socket_name_ssh, redir_socket_name_ssh);
    }
}