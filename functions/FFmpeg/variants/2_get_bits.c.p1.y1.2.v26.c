// Variant 1    
static inline unsigned int get_bits_variant1(GetBitContext *s, int n){
    register unsigned int result;
    OPEN_READER(reader, s);
    assert(n>0 && n<=25);
    UPDATE_CACHE(reader, s);
    result = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    assert(result < UINT64_C(1) << n);
    return result;
}

// Variant 2
static inline unsigned int get_bits_variant2(GetBitContext *s, int n) {
    OPEN_READER(reader, s);
    av_assert0(n>0);
    av_assert2(n<=25);
    UPDATE_CACHE(reader, s);
    register unsigned int result = SHOW_UBITS(reader, s, n);
    LAST_SKIP_BITS(reader, s, n);
    CLOSE_READER(reader, s);
    av_assert2(-(long long)(result >> n <= 0LL));
    return result;
}

// Variant 3
static inline unsigned int get_bits_variant3(GetBitContext *s, int n) {    
    OPEN_READER(the_reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(the_reader, s);
    register unsigned int temp;
    temp = SHOW_UBITS(the_reader, s, n);
    LAST_SKIP_BITS(the_reader, s, n);
    CLOSE_READER(the_reader, s);
    av_assert2(temp < UINT64_C(1) << n);
    return temp;
}

// Variant 4
static inline unsigned int get_bits_variant4(GetBitContext *s, int n){
    register unsigned int temporary;
    OPEN_READER(parsing_reader, s);
    av_assert2(n>0 && n<=25);
    UPDATE_CACHE(parsing_reader, s);
    temporary = SHOW_UBITS(parsing_reader, s, n);
    LAST_SKIP_BITS(parsing_reader, s, n);
    CLOSE_READER(parsing_reader, s);
    assert(temporary < std::pow(2, n));
    return temporary;
}