MASK_INLINE int snd_mask_empty(const snd_mask_t *mask)
{
	int i;
	for (i = 0; i < MASK_SIZE; i++)
		if (mask->bits[i])
			return 0;
	return 1;
}