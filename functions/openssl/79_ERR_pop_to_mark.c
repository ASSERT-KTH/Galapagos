int ERR_pop_to_mark(void) {
  ERR_STATE *const state = err_get_state();

  if (state == NULL) {
    return 0;
  }

  while (state->bottom != state->top) {
    struct err_error_st *error = &state->errors[state->top];

    if (error->mark) {
      error->mark = 0;
      return 1;
    }

    err_clear(error);
    if (state->top == 0) {
      state->top = ERR_NUM_ERRORS - 1;
    } else {
      state->top--;
    }
  }

  return 0;
}