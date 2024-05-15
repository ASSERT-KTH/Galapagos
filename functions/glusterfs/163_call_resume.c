call_resume (call_stub_t *stub)
{
        xlator_t *old_THIS = NULL;

        errno = EINVAL;
        GF_VALIDATE_OR_GOTO ("call-stub", stub, out);

        list_del_init (&stub->list);

        old_THIS = THIS;
        THIS = stub->frame->this;
        {
                if (stub->wind)
                        call_resume_wind (stub);
                else
                        call_resume_unwind (stub);
        }
        THIS = old_THIS;

        call_stub_destroy (stub);
out:
        return;
}