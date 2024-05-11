cleanup (void)
{
  if (socket_name && *socket_name)
    {
      char *name;

      name = redir_socket_name? redir_socket_name : socket_name;

      gnupg_remove (name);
      *socket_name = 0;
    }
}