static void socketcan_free(can_context_t * ctx) {

	if (ctx) {
		if (ctx->socket >= 0) {
			close(ctx->socket);
		}
		free(ctx);
	}
}