INTERVAL_INLINE void snd_interval_set_value(snd_interval_t *i, unsigned int val)
{
	i->openmax = i->openmin = 0;
	i->min = i->max = val;
	i->integer = 0;
	i->empty = 0;
}