btc_stack_get(const btc_stack_t *stack, int index) {
  if (index < 0)
    index += (int)stack->length;

  CHECK((size_t)index < stack->length);

  return (btc_buffer_t *)stack->items[index];
}