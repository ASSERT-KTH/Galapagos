#include <stdint.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps) 
{
    int count = 16;
    int overhead = (7 + bps + 7) / 8;
    
    count += ch * overhead;
    
    if (ch == 2) {
        count += ((2 * bps + 1) * blocksize + 7) / 8;
    } else {
        count += (ch * bps * blocksize + 7) / 8;
    }
    
    count += 2;
    
    return count;
}


int main(){
    flac_get_max_frame_size(0,0,0);
}
