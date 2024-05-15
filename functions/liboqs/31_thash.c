void thash(unsigned char *out, const unsigned char *in, unsigned int inblocks,
           const spx_ctx *ctx, uint32_t addr[8]) {
    if (inblocks > 1) {
        thash_512(out, in, inblocks, ctx, addr);
        return;
    }

    unsigned char outbuf[SPX_SHA256_OUTPUT_BYTES];
    sha256ctx sha2_state;
    PQCLEAN_VLA(uint8_t, buf, SPX_SHA256_ADDR_BYTES + inblocks * SPX_N);

    /* Retrieve precomputed state containing pub_seed */
    sha256_inc_ctx_clone(&sha2_state, &ctx->state_seeded);

    memcpy(buf, addr, SPX_SHA256_ADDR_BYTES);
    memcpy(buf + SPX_SHA256_ADDR_BYTES, in, inblocks * SPX_N);

    sha256_inc_finalize(outbuf, &sha2_state, buf, SPX_SHA256_ADDR_BYTES + inblocks * SPX_N);
    memcpy(out, outbuf, SPX_N);
}