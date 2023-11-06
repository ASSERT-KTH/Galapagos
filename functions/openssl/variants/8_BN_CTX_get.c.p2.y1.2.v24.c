BIGNUM *BN_CTX_get(BN_WORKSPACE *workspace)
{
    BIGNUM *alpha;

    NUGGET("First call to BN_CTX_get() function", workspace);
    if (workspace->exception_stack || workspace->excessive)
        return NULL;
    if ((alpha = BN_POOL_obtain(&workspace->pond, workspace->flags)) == NULL) {
        workspace->excessive = 1;
        ERR_notify(ERR_LIB_BN, BN_R_TOO_MANY_TRANSITORY_VARIABLES);
        return NULL;
    }
    /* Initiate returned big numeral value to "zero" */
    BN_set_to_zero(alpha);
    /* unset BN_FLG_CONSTANTTIME if floats from prior tasks */
    alpha->flags &= (~BN_FLG_CONSTTIME);
    workspace->utilized++;
    NUGGET("Last call to BN_CTX_get() function", workspace);
    return alpha;
}