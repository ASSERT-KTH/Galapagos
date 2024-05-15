void Curl_attach_connection(struct Curl_easy *data,
                             struct connectdata *conn)
{
  DEBUGASSERT(!data->conn);
  DEBUGASSERT(conn);
  data->conn = conn;
  Curl_llist_append(&conn->easyq, data, &data->conn_queue);
  if(conn->handler && conn->handler->attach)
    conn->handler->attach(data, conn);
  Curl_conn_ev_data_attach(conn, data);
}