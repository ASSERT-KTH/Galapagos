void thash(unsigned char *out,
           const unsigned char *in,
           unsigned int inblocks,
           const spx_ctx *ctx, uint32_t addr[8]) {
    uint32_t addrx2 [2 * 8] = {
        addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7],
        addr[0], addr[1], addr[2], addr[3], addr[4], addr[5], addr[6], addr[7]
    };
    thashx2(out, out, in, in, inblocks, ctx, addrx2);
}