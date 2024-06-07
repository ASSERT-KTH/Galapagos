package main

func flacGetMaxFrameSize(blocksize, ch, bps int32) int32 {
    count := int32(16)
    count += ch * ((7 + bps + 7) / 8)
    if ch == 2 {
        count += ((2*bps + 1) * blocksize + 7) / 8
    } else {
        count += (ch * bps * blocksize + 7) / 8
    }
    count += 2
    return count
}


func main(){
    flacGetMaxFrameSize(0,0,0)
}
