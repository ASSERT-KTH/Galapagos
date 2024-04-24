http_conn_abort(http_conn_t *conn) {
  if (conn->req != NULL)
    http_req_destroy(conn->req);

  btc_socket_close(conn->socket);

  conn->req = NULL;
  conn->last_was_value = 0;
  conn->total_buffered = 0;

  return 1;
}