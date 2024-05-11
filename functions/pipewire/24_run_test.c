static void run_test(const char *name, const char *impl, bool in_packed, bool out_packed, convert_func_t func)
{
	SPA_FOR_EACH_ELEMENT_VAR(sample_sizes, s) {
		SPA_FOR_EACH_ELEMENT_VAR(channel_counts, c) {
			run_test1(name, impl, in_packed, out_packed, func, *c, (*s + (*c -1)) / *c);
		}
	}
}