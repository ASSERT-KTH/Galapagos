#include <stdint.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps) 
{
    int base = 16;
    int audio_frame_size = (ch * (bps + 14)) / 8;
    int side_info_size = (ch == 2) ? ((2 * bps + 1) * blocksize + 7) / 8 : (ch * bps * blocksize + 7) / 8;
    
    return base + audio_frame_size + side_info_size + 2;
}


int main(){
    flac_get_max_frame_size(0,0,0);
}
