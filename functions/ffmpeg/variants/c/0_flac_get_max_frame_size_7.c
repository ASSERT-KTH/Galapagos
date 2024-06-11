#include <stdint.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps) 
{
    int base = 16;
    int audio_frame = ch * ((7 + bps + 7) / 8);
    
    int payload = (ch == 2) ? ((2 * bps + 1) * blocksize + 7) / 8 : (ch * bps * blocksize + 7) / 8;
    
    return base + audio_frame + payload + 2;
}


int main(){
    flac_get_max_frame_size(0,0,0);
}
