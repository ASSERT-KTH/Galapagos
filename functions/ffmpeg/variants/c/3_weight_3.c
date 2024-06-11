#include <stdint.h>

static int weight(int i, int blen, int offset)
{
    if (offset == 1) {
        return (i < 2 * offset) ? ((i) ? 5 : 3) : ((i > blen - 1 - 2 * offset) ? ((blen - 1 - i) ? 5 : 3) : 8);
    } else {
        return (i < 2 * offset) ? (1 + (6 * i + offset - 1) / (2 * offset - 1)) : ((i > blen - 1 - 2 * offset) ? (1 + (6 * (blen - 1 - i) + offset - 1) / (2 * offset - 1)) : 8);
    }
}


int main(){
    weight(0,0,0);
}
