#include <stdint.h>

static int weight(int i, int blen, int offset)
{
    int result;
    if (i < 2 * offset) {
        result = offset == 1 ? (i ? 5 : 3) : (1 + (6 * i + offset - 1) / (2 * offset - 1));
    } else if (i > blen - 1 - 2 * offset) {
        result = offset == 1 ? ((blen - 1 - i) ? 5 : 3) : (1 + (6 * (blen - 1 - i) + offset - 1) / (2 * offset - 1));
    } else {
        result = 8;
    }
    return result;
}


int main(){
    weight(0,0,0);
}
