load_3(const unsigned char *in)
{
    uint64_t result=0;
    int counter = 0;

    while(counter < 3) {
        result += ((uint64_t) in[counter]) << (counter * 8);
        counter++;
    }

    return result;
}