btc_writer_push_data(btc_writer_t *z, const uint8_t *data, size_t length) {
  btc_opcode_t *op = btc_opcode_create();

  btc_opcode_set_push(op, data, length);

  btc_writer_push(z, op);
}