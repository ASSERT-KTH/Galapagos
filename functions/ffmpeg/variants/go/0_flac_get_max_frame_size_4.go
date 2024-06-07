package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    count := int32(16)
    count += ch * ((bps + 14) / 8)
    if ch == 2 {
        frameSize := ((2*bps + 1) * blocksize + 7) / 8
        count += frameSize
    } else {
        frameSize := (ch * bps * blocksize + 7) / 8
        count += frameSize
    }
    count += 2
    return count
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
