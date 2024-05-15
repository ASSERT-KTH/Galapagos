cbc_enc (unsigned char *out, unsigned char *in, unsigned char *iv,
	 unsigned int len)
{
    size_t i;
    cam_rval r;
    unsigned char tmp[B];
    D(iv);
    memcpy (tmp, iv, B);
    for (i = 0; i < len; i += B) {
	D(in+i);
	xor (tmp, tmp, in + i);
	D(tmp);
	r = camellia_enc_blk (tmp, out + i, &ctx);
	if (!r) fprintf(stderr, "error, line %d\n", __LINE__), exit(1);
	memcpy (tmp, out + i, B);
	D(out+i);
    }
    if (i != len) abort ();
}