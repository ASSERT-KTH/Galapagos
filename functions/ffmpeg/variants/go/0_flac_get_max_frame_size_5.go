package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    count := int32(16)
    channels := ch * ((7 + bps + 7) / 8)
    var frameSize int32 = 0
    if ch == 2 {
        frameSize = ((2*bps + 1) * blocksize + 7) / 8
    } else {
        frameSize = (ch * bps * blocksize + 7) / 8
    }
    count += channels + frameSize + 2
    return count
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
