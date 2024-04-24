rb_iter_next(rb_iter_t *iter) {
  if (iter->node == NIL)
    return 0;

  iter->node = rb_node_successor(iter->node);

  return 1;
}