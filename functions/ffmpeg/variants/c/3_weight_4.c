#include <stdint.h>

static int weight(int i, int blen, int offset)
{
    int ret = 8;
    if (i < 2 * offset) {
        ret = (offset == 1) ? (i ? 5 : 3) : 1 + (6 * i + offset - 1) / (2 * offset - 1);
    } else if (i > blen - 1 - 2 * offset) {
        ret = (offset == 1) ? ((blen - 1 - i) ? 5 : 3) : 1 + (6 * (blen - 1 - i) + offset - 1) / (2 * offset - 1);
    }
    return ret;
}


int main(){
    weight(0,0,0);
}
