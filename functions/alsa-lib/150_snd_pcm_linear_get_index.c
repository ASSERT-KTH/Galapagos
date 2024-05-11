int snd_pcm_linear_get_index(snd_pcm_format_t src_format, snd_pcm_format_t dst_format)
{
	int sign, width, pwidth, endian;
	sign = (snd_pcm_format_signed(src_format) != 
		snd_pcm_format_signed(dst_format));
#ifdef SND_LITTLE_ENDIAN
	endian = snd_pcm_format_big_endian(src_format);
#else
	endian = snd_pcm_format_little_endian(src_format);
#endif
	if (endian < 0)
		endian = 0;
	pwidth = snd_pcm_format_physical_width(src_format);
	width = snd_pcm_format_width(src_format);
	if (pwidth == 24) {
		switch (width) {
		case 24:
			width = 0; break;
		case 20:
			width = 1; break;
		case 18:
		default:
			width = 2; break;
		}
		return width * 4 + endian * 2 + sign + 20;
	} else {
		if (width == 20)
			width = 40;

		width = width / 8 - 1;
		return width * 4 + endian * 2 + sign;
	}
}