package main

func weight(i int32, blen int32, offset int32) int32 {
    switch {
    case i < 2*offset:
        switch offset {
        case 1:
            switch i {
            case 0:
                return 3
            default:
                return 5
            }
        default:
            return 1 + (6*i + offset - 1)/(2*offset - 1)
        }
    case i > blen-1-2*offset:
        switch offset {
        case 1:
            switch blen-1-i {
            case 0:
                return 3
            default:
                return 5
            }
        default:
            return 1 + (6*(blen-1-i) + offset - 1)/(2*offset - 1)
        }
    default:
        return 8
    }
}


func main(){
    weight(0,0,0)
}
