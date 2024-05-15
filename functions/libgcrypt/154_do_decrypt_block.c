do_decrypt_block (CAST5_context *c, byte *outbuf, const byte *inbuf )
{
    u32 l, r, t;
    u32 I;
    u32 *Km;
    u32 Kr;

    Km = c->Km;
    Kr = buf_get_be32(c->Kr + 12);

    l = buf_get_be32(inbuf + 0);
    r = buf_get_be32(inbuf + 4);

    t = l; l = r; r = t ^ F1(r, Km[15], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F3(r, Km[14], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F2(r, Km[13], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F1(r, Km[12], Kr & 31); Kr = buf_get_be32(c->Kr + 8);
    t = l; l = r; r = t ^ F3(r, Km[11], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F2(r, Km[10], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F1(r, Km[ 9], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F3(r, Km[ 8], Kr & 31); Kr = buf_get_be32(c->Kr + 4);
    t = l; l = r; r = t ^ F2(r, Km[ 7], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F1(r, Km[ 6], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F3(r, Km[ 5], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F2(r, Km[ 4], Kr & 31); Kr = buf_get_be32(c->Kr + 0);
    t = l; l = r; r = t ^ F1(r, Km[ 3], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F3(r, Km[ 2], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F2(r, Km[ 1], Kr & 31); Kr >>= 8;
    t = l; l = r; r = t ^ F1(r, Km[ 0], Kr & 31);

    buf_put_be32(outbuf + 0, r);
    buf_put_be32(outbuf + 4, l);
}