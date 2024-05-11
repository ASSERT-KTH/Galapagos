cleanup (void)
{
  static int done;

  if (done)
    return;
  done = 1;
  if (!inhibit_socket_removal)
    remove_socket (socket_name);
}