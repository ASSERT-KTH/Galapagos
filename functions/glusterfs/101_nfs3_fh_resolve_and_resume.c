nfs3_fh_resolve_and_resume (nfs3_call_state_t *cs, struct nfs3_fh *fh,
                            char *entry, nfs3_resume_fn_t resum_fn)
{
        int     ret = -EFAULT;

        if ((!cs) || (!fh))
                return ret;

        cs->resume_fn = resum_fn;
        cs->resolvefh = *fh;
        cs->hashidx = 0;

        /* Check if the resolution is:
         * a. fh resolution
         *
         * or
         *
         * b. (fh, basename) resolution
         */
        if (entry) {    /* b */
                cs->resolventry = gf_strdup (entry);
                if (!cs->resolventry)
                        goto err;
        }

        ret = nfs3_fh_resolve_root (cs);
err:
        return ret;
}