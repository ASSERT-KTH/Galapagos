dns_b_putc(struct dns_buf *b, unsigned char uc)
{
	if (!(b->p < b->pe))
		return dns_b_setoverflow(b, 1, DNS_ENOBUFS);

	*b->p++ = uc;

	return 0;
}