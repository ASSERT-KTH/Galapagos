void Curl_detach_connection(struct Curl_easy *data)
{
  struct connectdata *conn = data->conn;
  if(conn) {
    Curl_conn_ev_data_detach(conn, data);
    Curl_llist_remove(&conn->easyq, &data->conn_queue, NULL);
  }
  data->conn = NULL;
}