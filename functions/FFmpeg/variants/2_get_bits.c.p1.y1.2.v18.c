Variant 1:

static inline unsigned int fetch_bits(GetBitContext *ctxt, int bit_number)
{
    register unsigned int inter;
    
    OPEN_READER(reader, ctxt);
    av_assert2(bit_number > 0 && bit_number <= 25);
    
    UPDATE_CACHE(reader, ctxt);
    inter = SHOW_UBITS(reader, ctxt, bit_number);
    
    LAST_SKIP_BITS(reader, ctxt, bit_number);
    
    CLOSE_READER(reader, ctxt);
    av_assert2(inter < UINT64_C(1) << bit_number);
    
    return inter;
}


Variant 2:

static inline unsigned int retrieve_bits(GetBitContext *area, int nbr)
{
    register unsigned int reg;
    
    OPEN_READER(rd, area);
    av_assert2(nbr > 0 && nbr <= 25);
    
    UPDATE_CACHE(rd, area);
    reg = SHOW_UBITS(rd, area, nbr);
    
    LAST_SKIP_BITS(rd, area, nbr);
    
    CLOSE_READER(rd, area);
    av_assert2(reg < UINT64_C(1) << nbr);
  
    return reg;
}


Variant 3:

static inline unsigned int obtain_bits(GetBitContext *src, int num)
{
    register unsigned int buffer;
    
    OPEN_READER(op, src);
    av_assert2(num > 0 && num <= 25);
    
    UPDATE_CACHE(op, src);
    buffer = SHOW_UBITS(op, src, num);
    
    LAST_SKIP_BITS(op, src, num);
    
    CLOSE_READER(op, src);
    av_assert2(buffer < UINT64_C(1) << num);
    
    return buffer;
}
