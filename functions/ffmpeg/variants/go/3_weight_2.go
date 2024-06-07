package main

func weight(i int32, blen int32, offset int32) int32 {
    if i < 2*offset {
        if offset == 1 {
            if i != 0 {
                return 5
            }
            return 3
        }
        return 1 + (6*i + offset - 1) / (2*offset - 1)
    }
    if i > blen-1-2*offset {
        if offset == 1 {
            if blen-1-i != 0 {
                return 5
            }
            return 3
        }
        return 1 + (6*(blen-1-i) + offset - 1) / (2*offset - 1)
    }
    return 8
}


func main(){
    weight(0,0,0)
}
