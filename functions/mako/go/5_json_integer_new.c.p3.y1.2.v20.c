It is highly important to note that semantic translations between programming languages have inherent potential for differences in reception due to aspects discontinued or just differences in language design. Equally, since Go does not allow arbitrary casting from one type to another or from pointer to non-pointer types and vice versa (like C does), and does not support union types, we need to make some changes in original code, hence some stuff in Go can be considered a comparable substitute.

To convert: An idiomatic representation with completely the same outcome is guaranteed impossible, since Go and C are quite different in terms of memory model and type system.

However, I will create equivalent Go code, trying to keep the most of the logic.

Here it is:

go
type JSONBuilderValue struct {
	IsBuilderValue bool     
	Type           JSONType
	Integer        int 
}

type JSONType int

const (
	Integer JSONType = iota
)

func newJSONInteger(integer int) *JSONBuilderValue {
	return &JSONBuilderValue{
		IsBuilderValue: true,
		Type:           Integer,
		Integer:        integer,
	}
}

In this code, I've treated "json_integer" as some kind of JSONType for making representation a bit even. In truth, your precise type structure and design may dictate divergent approach.

Note: As you might see this is truly pragmatic instead of literal conversion, due to aforesaid dissimilarities amid languages.

Optional Note: Breaking free memory is not needed here, since Go incorporates garbage eradication itself; it eradicates memory automatically when there are no left references to object.