xlator_mem_acct_init (xlator_t *xl, int num_types)
{
        int             i = 0;
        int             ret = 0;

        if (!xl)
                return -1;

        if (!xl->ctx->mem_acct_enable)
                return 0;

        xl->mem_acct.num_types = num_types;

        xl->mem_acct.rec = CALLOC(num_types, sizeof(struct mem_acct_rec));

        if (!xl->mem_acct.rec) {
                return -1;
        }

        for (i = 0; i < num_types; i++) {
                ret = LOCK_INIT(&(xl->mem_acct.rec[i].lock));
                if (ret) {
                        fprintf(stderr, "Unable to lock..errno : %d",errno);
                }
        }

        return 0;
}