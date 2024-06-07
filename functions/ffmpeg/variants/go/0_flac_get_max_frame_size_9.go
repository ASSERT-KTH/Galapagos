package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    baseSize := int32(16)
    perChannel := ch * ((7 + bps + 7) / 8)
    var frameContentSize int32
    if ch == 2 {
        frameContentSize = ((2*bps + 1) * blocksize + 7) / 8
    } else {
        frameContentSize = (ch * bps * blocksize + 7) / 8
    }
    totalSize := baseSize + perChannel + frameContentSize + 2
    return totalSize
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
