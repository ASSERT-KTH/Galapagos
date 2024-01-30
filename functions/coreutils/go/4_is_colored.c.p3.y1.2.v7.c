In Go language, the equivalent implementation might look like this:

go
import "strings"

type ColorIndicator struct {
	len    int
	string string
}

func isColored(color_indicator []ColorIndicator, _type int) bool {
	len := color_indicator[_type].len
	s := color_indicator[_type].string
	return !(len == 0 ||
		(len == 1 && strings.Compare(s, "0") == 0) || 
		(len == 2 && strings.Compare(s, "00") == 0))
}
 

Noticed a number of things: 

1. Go does not support type `enum`. You could define your constants or use an `int`.

2. Go does not support exact replacements for Macros but you can achieve a similar functionality using function/methods.

3. In Go, to compare two strings, you should use the `Compare` function from the `strings` package instead. 

4. Go has a different naming convention(CamelCase) as it is case sensitive. Use underline names (_type) to only when dealing with conflict names. 

In a real life use-case irrespective of the language you're using to map to, the most crucial bit is ensuring you map business logic of every bit you change and to consider how the typing changes the behavior. Be more careful on cases where the language itself does not support some of the data types.

Also the initial `struct` should be defined more globally in actual. Here the struct `ColorIndicator` is only defined prior for demonstration purposes as we're only focused on function implementation!  