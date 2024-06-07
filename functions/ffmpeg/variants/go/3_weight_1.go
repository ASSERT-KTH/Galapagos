package main

func weight(i, blen, offset int32) int32 {
    switch {
    case i < 2*offset:
        if offset == 1 {
            if i == 0 {
                return 3
            }
            return 5
        }
        return 1 + (6*i + offset - 1) / (2*offset - 1)
    case i > blen-1-2*offset:
        if offset == 1 {
            if blen-1-i == 0 {
                return 3
            }
            return 5
        }
        return 1 + (6*(blen-1-i) + offset - 1) / (2*offset - 1)
    default:
        return 8
    }
}


func main(){
    weight(0,0,0)
}
