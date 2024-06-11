#include <stdint.h>

static int flac_get_max_frame_size(int blocksize, int ch, int bps) 
{
    int count = 16;
    count += ch * ((7 + bps + 7) / 8);
    int audio_data_size = (ch == 2) ? ((2 * bps + 1) * blocksize + 7) / 8 : (ch * bps * blocksize + 7) / 8;
    
    count += audio_data_size + 2;
    
    return count;
}


int main(){
    flac_get_max_frame_size(0,0,0);
}
