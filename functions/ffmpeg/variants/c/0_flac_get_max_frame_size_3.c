#include <stdint.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps) 
{
    int count = 16;
    count += ch * ((bps + 14) / 8);
    
    int size;
    if (ch == 2) {
        size = ((2 * bps + 1) * blocksize + 7) / 8;
    } else {
        size = (ch * bps * blocksize + 7) / 8;
    }
    count += size;
    
    count += 2;
    
    return count;
}


int main(){
    flac_get_max_frame_size(0,0,0);
}
