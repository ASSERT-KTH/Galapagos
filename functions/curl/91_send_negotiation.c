static void send_negotiation(struct Curl_easy *data, int cmd, int option)
{
  unsigned char buf[3];
  ssize_t bytes_written;
  struct connectdata *conn = data->conn;

  buf[0] = CURL_IAC;
  buf[1] = (unsigned char)cmd;
  buf[2] = (unsigned char)option;

  bytes_written = swrite(conn->sock[FIRSTSOCKET], buf, 3);
  if(bytes_written < 0) {
    int err = SOCKERRNO;
    failf(data,"Sending data failed (%d)",err);
  }

  printoption(data, "SENT", cmd, option);
}