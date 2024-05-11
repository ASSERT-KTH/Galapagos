static struct dns_packet *dns_p_setptr(struct dns_packet **dst, struct dns_packet *src) {
	dns_p_free(*dst);

	*dst = src;

	return src;
} /* dns_p_setptr() */