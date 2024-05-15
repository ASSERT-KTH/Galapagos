memdup (const void *ptr, size_t size)
{
	void *newptr = NULL;

	newptr = GF_MALLOC (size, gf_common_mt_memdup);
	if (!newptr)
		return NULL;

	memcpy (newptr, ptr, size);
	return newptr;
}