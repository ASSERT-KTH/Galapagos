package main

func ulaw_to_s16(u_val uint8) int32 {
    u_val = ^u_val
    
    quant_bits := (int32(u_val&0x0f) << 3) + 0x84
    segment_shift := (u_val & 0x70) >> 4
    t := quant_bits << segment_shift
    
    if (u_val & 0x80) != 0 {
        return 0x84 - t
    }
    return t - 0x84
}


func main(){
    ulaw_to_s16('a')
}
