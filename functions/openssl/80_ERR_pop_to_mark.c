int ERR_pop_to_mark(void)
{
    ERR_STATE *es;

    es = ossl_err_get_state_int();
    if (es == NULL)
        return 0;

    while (es->bottom != es->top
           && es->err_marks[es->top] == 0) {
        err_clear(es, es->top, 0);
        es->top = es->top > 0 ? es->top - 1 : ERR_NUM_ERRORS - 1;
    }

    if (es->bottom == es->top)
        return 0;
    es->err_marks[es->top]--;
    return 1;
}