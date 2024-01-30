The given C code snippet seems include a reference to a variable 'args' that has never been declared or initialzed within the same function scope. Due to lack of complete context and precise details, it's hard to provide an exact Go equivalence without assuming something about that variables. 

I'll presume that 'args' is probably meant to be globale variable or equivalent and it's supposed to be a pointer to a null-terminated array of string. I'll add missing pieces like including complete function definition with return type:

In C:

#include <stdbool.h>
#include <string.h>

char const **args;

bool nextarg (char const *str)
{
    if (*args == NULL)
     return false;
    else
    {
        bool r = (strcmp(*args, str) == 0);
        args += r;
        return r;
    }
}


The equivalent Go code might be:

Go
// args is a slice of strings, indexed by a global counter
var (
	args   []string
	argsIdx int
)

func nextarg(str string) bool {
	if argsIdx >= len(args) {
		return false
	}
	r := (args[argsIdx] == str)
	argsIdx += boolToInt(r)
	return r
}

func boolToInt(b bool) int {
	if b {
		return 1
	}
	return 0
}

I have used a additional helper function boolToInt, which converts Boolean value into integer. While Go doesn't provide such direct conversions unlike C. This strong type safety isn't a problem because instead of incrementing on compare result, I can intersperse checking and incrementation. Hopefully this will be acceptable, given the requirement for an equivalent semantics & functional activity.