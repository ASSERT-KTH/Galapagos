mdc_local_get (call_frame_t *frame)
{
        mdc_local_t *local = NULL;

        local = frame->local;
        if (local)
                goto out;

        local = GF_CALLOC (sizeof (*local), 1, gf_mdc_mt_mdc_local_t);
        if (!local)
                goto out;

        frame->local = local;
out:
        return local;
}