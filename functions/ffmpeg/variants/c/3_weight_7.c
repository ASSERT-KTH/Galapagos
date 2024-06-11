#include <stdint.h>

static int weight(int i, int blen, int offset)
{
    if (i < 2 * offset) {
        if (offset == 1) {
            return (i ? 5 : 3);
        } else {
            return 1 + (6 * i + offset - 1) / (2 * offset - 1);
        }
    } else if (i > blen - 1 - 2 * offset) {
        if (offset == 1) {
            return ((blen - 1 - i) ? 5 : 3);
        } else {
            return 1 + (6 * (blen - 1 - i) + offset - 1) / (2 * offset - 1);
        }
    }
    return 8;
}


int main(){
    weight(0,0,0);
}
