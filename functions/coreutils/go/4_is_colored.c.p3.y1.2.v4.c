Assuming that colorIndicator variable exists in your Go program as a map[string]struct{ Len int ; Str string }, I'm writing the function equivalent. If it doesn't, you have to rearrange the code.

go
type Indicator int

const (
    IndicatorOne Indicator = iota
    IndicatorTwo
)

var colorIndicator = map[Indicator]struct {
    Len int
    Str string
}{
    IndicatorOne: {Len: 1, Str: "1"},
    IndicatorTwo: {Len: 2, Str: "2"},
}

func isColored(indicator Indicator) bool {
    ci := colorIndicator[indicator]
    switch ci.Len {
    case 0, 1:
        if ci.Str == "0" {
            return false
        }
    case 2:
        if ci.Str == "00" {
            return false
        }
    }
    return true
}
