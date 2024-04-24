int ERR_clear_last_mark(void)
{
    ERR_STATE *es;
    int top;

    es = ossl_err_get_state_int();
    if (es == NULL)
        return 0;

    top = es->top;
    while (es->bottom != top
           && es->err_marks[top] == 0) {
        top = top > 0 ? top - 1 : ERR_NUM_ERRORS - 1;
    }

    if (es->bottom == top)
        return 0;
    es->err_marks[top]--;
    return 1;
}