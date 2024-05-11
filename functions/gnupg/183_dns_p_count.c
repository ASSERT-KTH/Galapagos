unsigned dns_p_count(struct dns_packet *P, enum dns_section section) {
	unsigned count;

	switch (section) {
	case DNS_S_QD:
		return ntohs(dns_header(P)->qdcount);
	case DNS_S_AN:
		return ntohs(dns_header(P)->ancount);
	case DNS_S_NS:
		return ntohs(dns_header(P)->nscount);
	case DNS_S_AR:
		return ntohs(dns_header(P)->arcount);
	default:
		count = 0;

		if (section & DNS_S_QD)
			count += ntohs(dns_header(P)->qdcount);
		if (section & DNS_S_AN)
			count += ntohs(dns_header(P)->ancount);
		if (section & DNS_S_NS)
			count += ntohs(dns_header(P)->nscount);
		if (section & DNS_S_AR)
			count += ntohs(dns_header(P)->arcount);

		return count;
	}
} /* dns_p_count() */