void pw_main_loop_destroy(struct pw_main_loop *loop)
{
	pw_log_debug("%p: destroy", loop);
	pw_main_loop_emit_destroy(loop);

	if (loop->created)
		pw_loop_destroy(loop->loop);

	spa_hook_list_clean(&loop->listener_list);

	free(loop);
}