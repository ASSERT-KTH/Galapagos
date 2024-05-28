static int weight(int i, int blen, int offset)
{
#define ROLLOFF(i) offset == 1 ? ((i) ? 5 : 3) :        \
    (1 + (6*(i) + offset - 1) / (2*offset - 1))

    if (i < 2*offset)
        return ROLLOFF(i);
    else if (i > blen-1 - 2*offset)
        return ROLLOFF(blen-1 - i);
    return 8;
}