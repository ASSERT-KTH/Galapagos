package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    header := int32(16)
    channels := (7 + bps + 7) / 8
    count := header + ch*channels
    var frameData int32
    if ch == 2 {
        frameData = ((2*bps + 1) * blocksize + 7) / 8
    } else {
        frameData = (ch * bps * blocksize + 7) / 8
    }
    count += frameData + 2
    return count
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
