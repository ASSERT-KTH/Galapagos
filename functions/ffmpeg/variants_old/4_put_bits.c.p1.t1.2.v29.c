static void put_bits(Jpeg2000EncoderContext *s, int val, int n) // TODO: optimize
{
	int bit;
	for (bit = 7; n > 0; bit--, n--)
	{
		if (bit == -1)
		{
			bit = 7;
			s->bit_index = *s->buf == 0xff ? 0 : 1 ;
			*(++s->buf) = 0;
		}
		*s->buf |= ((val >> (n - 1)) & 1) << bit;
	}
}