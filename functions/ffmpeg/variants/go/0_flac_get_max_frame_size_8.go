package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    count := int32(16)
    channelSize := ch * ((bps + 14) / 8)
    var dataSize int32
    if ch == 2 {
        dataSize = ((2*bps + 1) * blocksize + 7) / 8
    } else {
        dataSize = (ch * bps * blocksize + 7) / 8
    }
    count += channelSize + dataSize + 2
    return count
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
