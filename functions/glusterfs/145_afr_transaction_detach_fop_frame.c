afr_transaction_detach_fop_frame (call_frame_t *frame)
{
        afr_local_t *   local = NULL;
        call_frame_t   *fop_frame = NULL;

        local = frame->local;

        LOCK (&frame->lock);
        {
                fop_frame = local->transaction.main_frame;
                local->transaction.main_frame = NULL;
        }
        UNLOCK (&frame->lock);

        return fop_frame;
}