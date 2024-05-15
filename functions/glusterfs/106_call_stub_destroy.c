call_stub_destroy (call_stub_t *stub)
{
        GF_VALIDATE_OR_GOTO ("call-stub", stub, out);

        if (stub->wind)
                call_stub_wipe_args (stub);
        else
                call_stub_wipe_args_cbk (stub);

        stub->stub_mem_pool = NULL;

        mem_put (stub);
out:
        return;
}