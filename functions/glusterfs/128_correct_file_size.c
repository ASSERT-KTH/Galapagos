static inline void correct_file_size(struct iatt *buf, stripe_fd_ctx_t *fctx,
	call_frame_t *prev)
{
	int index;

	if (!IA_ISREG(buf->ia_type))
		return;

	if (!fctx || !fctx->stripe_coalesce)
		return;

	index = stripe_get_frame_index(fctx, prev);
	buf->ia_size = uncoalesced_size(buf->ia_size, fctx->stripe_size,
		fctx->stripe_count, index);
}