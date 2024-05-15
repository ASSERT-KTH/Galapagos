fuse_resolve_and_resume (fuse_state_t *state, fuse_resume_fn_t fn)
{
        fuse_gfid_set (state);

        state->resume_fn = fn;

        fuse_resolve_all (state);

        return 0;
}