resolve_and_resume (call_frame_t *frame, server_resume_fn_t fn)
{
        server_state_t    *state = NULL;

        state = CALL_STATE (frame);
        state->resume_fn = fn;

        server_resolve_all (frame);

        return 0;
}