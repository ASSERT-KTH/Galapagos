ascii_strcasecmp( const char *a, const char *b )
{
    if (a == b)
        return 0;

    for (; *a && *b; a++, b++) {
	if (*a != *b && ascii_toupper(*a) != ascii_toupper(*b))
	    break;
    }
    return *a == *b? 0 : (ascii_toupper (*a) - ascii_toupper (*b));
}