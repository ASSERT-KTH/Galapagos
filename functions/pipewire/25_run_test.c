static void run_test(const char *name, const char *impl, mix_func_t func)
{
	size_t i, j;

	for (i = 0; i < SPA_N_ELEMENTS(sample_sizes); i++) {
		for (j = 0; j < SPA_N_ELEMENTS(src_counts); j++) {
			run_test1(name, impl, func, src_counts[j],
				(sample_sizes[i] + (src_counts[j] -1)) / src_counts[j]);
		}
	}
}