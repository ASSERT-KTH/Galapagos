static void *dns_sa_addr(int af, const void *sa, socklen_t *size) {
	switch (af) {
	case AF_INET6: {
		struct in6_addr *in6 = &((struct sockaddr_in6 *)sa)->sin6_addr;

		if (size)
			*size = sizeof *in6;

		return in6;
	}
	case AF_INET: {
		struct in_addr *in = &((struct sockaddr_in *)sa)->sin_addr;

		if (size)
			*size = sizeof *in;

		return in;
	}
	default:
		if (size)
			*size = 0;

		return 0;
	}
} /* dns_sa_addr() */