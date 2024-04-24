btc_stack_get_num(int64_t *num,
                  const btc_stack_t *stack,
                  int index,
                  int minimal,
                  size_t limit) {
  const btc_buffer_t *buf = btc_stack_get(stack, index);

  if (buf->length > limit)
    return 0;

  if (minimal && !btc_scriptnum_is_minimal(buf->data, buf->length))
    return 0;

  *num = btc_scriptnum_import(buf->data, buf->length);

  return 1;
}