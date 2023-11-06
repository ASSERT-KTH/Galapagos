func nextArg(str string, args *string) bool {
	if *args == nil {
		return false
	} else {
		r := *args == str
		*args = *args + fmt.Sprintf("%v", r)
		return r
	}
}