#include <stdint.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps) 
{
    int count = 16;
    int bits_per_sample = (bps + 14) / 8;
    count += ch * bits_per_sample;
    
    int frame_payload;
    if (ch == 2) {
        frame_payload = ((2 * bps + 1) * blocksize + 7) / 8;
    } else {
        frame_payload = (ch * bps * blocksize + 7) / 8;
    }
    count += frame_payload;
    
    count += 2;
    
    return count;
}


int main(){
    flac_get_max_frame_size(0,0,0);
}
