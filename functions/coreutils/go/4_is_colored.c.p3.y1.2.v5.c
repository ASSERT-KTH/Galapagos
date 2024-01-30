Go doesn't directly support the equivalent of C's "enum". In golang we use const with iota to serve a similar purpose.

Assuming `color_indicator` is represented by map[int]Indicator in Go while `Indicator` is present in Go as:

go
type Indicator struct {
	len    int
	string string
}

Now, the equivalent Go function can be written as:

go
func is_colored(type indicatorNo) bool {
    len := color_indicator[type].len
    s := color_indicator[type].string
    return !(len == 0 || (len == 1 && s == "0") || (len == 2 && s == "00"))
} 


A lot of assumptions was made coming up with this code as C code was assuming a lot of globals and contextual data. Above Go implementation might need to tweak according to actual context.