In Go, we can write the equivalent function as below but considering few assumption such as ncolumns and columns are global variable and of struct, struct was not specified hence assuming myStruct as dummy structure which can be replaced as per real implementation. Also assuming that affirm performs which stops functionality like 'assert' function which is not a typical one in go.

Here is the reference implementation in Go:

Go
type myStruct struct {
    used    bool
    caption string
}

var (
    ncolumns  = 0
    columns   []*myStruct
    field_data [10]myStruct
)

func alloc_field(f int, c *string) {

    ncolumns++
    if c != nil {
        temp := &field_data[f]
        temp.caption = *c
        columns = append(columns[:ncolumns-1], temp)
    } else {
        columns = append(columns[:ncolumns-1], &field_data[f])
    }

    if field_data[f].used{
        panic("Assertion failed: !field_data[f].used")
    }

    // Mark field as used
    field_data[f].used = true
}


Please note that in case of the affirm method in the original C example, Go doesn't have similar direct assertions like in C, Hence used panic to raise an exception (i.e., panic()) when `field_data[f].used` is `true`.
However, as per Go's idiomatic practices, it is beneficial to return an associated error and manage assertions/logic with contiguous standard error handling, rather than panic.