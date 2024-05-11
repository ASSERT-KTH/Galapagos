int snd_seq_event_output(snd_seq_t *seq, snd_seq_event_t *ev)
{
	int result;

	result = snd_seq_event_output_buffer(seq, ev);
	if (result == -EAGAIN) {
		result = snd_seq_drain_output(seq);
		if (result < 0)
			return result;
		return snd_seq_event_output_buffer(seq, ev);
	}
	return result;
}