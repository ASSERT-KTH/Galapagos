void freeaddrinfo (struct addrinfo *ai)
{
#ifdef COPY_FIRST_CANONNAME
    if (ai) {
        free(ai->ai_canonname);
        ai->ai_canonname = 0;
        system_freeaddrinfo(ai);
    }
#else
    system_freeaddrinfo(ai);
#endif
}