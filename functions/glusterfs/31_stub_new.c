stub_new (call_frame_t *frame,
          char wind,
          glusterfs_fop_t fop)
{
        call_stub_t *new = NULL;

        GF_VALIDATE_OR_GOTO ("call-stub", frame, out);

        new = mem_get0 (frame->this->ctx->stub_mem_pool);
        GF_VALIDATE_OR_GOTO ("call-stub", new, out);

        new->frame = frame;
        new->wind = wind;
        new->fop = fop;
        new->stub_mem_pool = frame->this->ctx->stub_mem_pool;
        INIT_LIST_HEAD (&new->list);

        INIT_LIST_HEAD (&new->args_cbk.entries);
out:
        return new;
}