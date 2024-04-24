int ERR_set_mark(void) {
  ERR_STATE *const state = err_get_state();

  if (state == NULL || state->bottom == state->top) {
    return 0;
  }
  state->errors[state->top].mark = 1;
  return 1;
}