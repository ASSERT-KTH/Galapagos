init (void)
{
    size_t i, j;
    cam_rval r;

    srand(42);
    for (i = 0; i < 16; i++)
	key[i] = 0xff & rand();
    memset(test_case, 0, sizeof(test_case));
    for (i = 0; i < NTESTS; i++)
	for (j = 0; j < test_case_len[i]; j++) {
	    test_case[i].input[j] = 0xff & rand();
	}

    r = camellia_enc_key (key, sizeof(key), &ctx);
    if (!r) fprintf(stderr, "error, line %d\n", __LINE__), exit(1);
    r = camellia_dec_key (key, sizeof(key), &dctx);
    if (!r) fprintf(stderr, "error, line %d\n", __LINE__), exit(1);
}