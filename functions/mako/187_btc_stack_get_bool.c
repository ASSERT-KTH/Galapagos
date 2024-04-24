btc_stack_get_bool(const btc_stack_t *stack, int index) {
  const btc_buffer_t *buf = btc_stack_get(stack, index);
  size_t i;

  for (i = 0; i < buf->length; i++) {
    if (buf->data[i] != 0) {
      /* Cannot be negative zero. */
      if (i == buf->length - 1 && buf->data[i] == 0x80)
        return 0;
      return 1;
    }
  }

  return 0;
}