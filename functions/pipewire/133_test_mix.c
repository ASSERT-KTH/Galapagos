static void test_mix(uint32_t src_chan, uint32_t src_mask, uint32_t dst_chan, uint32_t dst_mask, uint32_t options, float *coeff)
{
	struct channelmix mix;

	spa_log_debug(&logger.log, "start %d->%d (%08x -> %08x)", src_chan, dst_chan, src_mask, dst_mask);

	spa_zero(mix);
	mix.options = options;
	mix.src_chan = src_chan;
	mix.dst_chan = dst_chan;
	mix.src_mask = src_mask;
	mix.dst_mask = dst_mask;
	mix.log = &logger.log;
	mix.fc_cutoff = 120.0f;
	mix.lfe_cutoff = 12000.0f;

	spa_assert_se(channelmix_init(&mix) == 0);
	channelmix_set_volume(&mix, 1.0f, false, 0, NULL);
	dump_matrix(&mix, coeff);
}