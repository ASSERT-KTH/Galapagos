btc_socket_close(btc_socket_t *socket) {
  btc_loop_t *loop = socket->loop;
  chunk_t *chunk, *next;

  if (socket->state == BTC_SOCKET_DISCONNECTED)
    return;

  for (chunk = socket->head; chunk != NULL; chunk = next) {
    next = chunk->next;

    if (chunk->addr != NULL)
      free(chunk->addr);

    free(chunk->ptr);
    free(chunk);
  }

  socket->state = BTC_SOCKET_DISCONNECTED;
  socket->head = NULL;
  socket->tail = NULL;
  socket->total = 0;
  socket->draining = 0;

  btc_list_push(&loop->closed, &socket->closed);
}