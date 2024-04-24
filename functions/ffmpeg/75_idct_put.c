static inline void idct_put(MadContext *t, AVFrame *frame, int16_t *block,
                            int mb_x, int mb_y, int j)
{
    if (j < 4) {
        ff_ea_idct_put_c(
            frame->data[0] + (mb_y*16 + ((j&2)<<2))*frame->linesize[0] + mb_x*16 + ((j&1)<<3),
            frame->linesize[0], block);
    } else if (!(t->avctx->flags & AV_CODEC_FLAG_GRAY)) {
        int index = j - 3;
        ff_ea_idct_put_c(
            frame->data[index] + (mb_y*8)*frame->linesize[index] + mb_x*8,
            frame->linesize[index], block);
    }
}