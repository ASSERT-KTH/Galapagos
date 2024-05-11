static int run_test(const char *name, const void *src[], uint32_t n_src, const void *dst,
		size_t dst_size, uint32_t n_samples, mix_func_t mix)
{
	struct mix_ops ops;

	ops.fmt = SPA_AUDIO_FORMAT_F32;
	ops.n_channels = 1;
	ops.cpu_flags = cpu_flags;
	mix_ops_init(&ops);

	fprintf(stderr, "%s\n", name);

	mix(&ops, (void *)samp_out, src, n_src, n_samples);
	compare_mem(0, 0, samp_out, dst, dst_size);
	return 0;
}