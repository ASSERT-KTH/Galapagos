int ERR_set_mark(void)
{
    ERR_STATE *es;

    es = ossl_err_get_state_int();
    if (es == NULL)
        return 0;

    if (es->bottom == es->top)
        return 0;
    es->err_marks[es->top]++;
    return 1;
}