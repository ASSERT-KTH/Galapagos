package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    base := int32(16)
    perChannel := (7 + bps + 7) / 8
    frameSize := int32(0)
    if ch == 2 {
        frameSize = ((2*bps + 1) * blocksize + 7) / 8
    } else {
        frameSize = (ch * bps * blocksize + 7) / 8
    }
    count := base + ch*perChannel + frameSize + 2
    return count
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
