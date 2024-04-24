static inline void put_rac(RangeCoder *c, uint8_t *const state, int bit)
{
    int range1 = (c->range * (*state)) >> 8;

    av_assert2(*state);
    av_assert2(range1 < c->range);
    av_assert2(range1 > 0);
    if (!bit) {
        c->range -= range1;
        *state    = c->zero_state[*state];
    } else {
        c->low  += c->range - range1;
        c->range = range1;
        *state   = c->one_state[*state];
    }

    renorm_encoder(c);
}