In Go, we can't use direct translation from C if we plan to maintain the same existing function and variable names due to syntactical differences in the languages.

Also, direct conversion of types and getting members' variables directly from a type (like `c->Vars` in C) is not available in Go like in C or C++. Instead, Go uses a dot (.) operator (like `value.method` in Java or C#), method receiver (like `func (m MyStruct) methodName() dataType{}`) to define methods on certain types or create getter method (like `func (m myStruct) GetVariableName() DataType {}`) to retrieve required variables' data members.

Given that, let's create a temporary Go version assuming use of struct method and dummy "errors.New" as error handling:

go
type BIGNUM struct {
    //variables
}

type BN_CTX struct {
    err_stack error
    too_many  bool
    pool      interface{}
    flags     []bool
    used      int
    // other context specific variables
}

func (ctx BN_CTX) Get() (*BIGNUM, error) {
    if ctx.err_stack != nil || ctx.too_many {
        return nil, ctx.err_stack
    }
    ret, err := ctx.poolGet(ctx.flags)
    if err != nil {
        ctx.too_many = true
        return nil, errors.New("too many temporary variables")
    }
    ret.zero()
    ret.flagsReset()
    ctx.used++
    return ret, nil
}

func (ctx BN_CTX) poolGet(flags []bool) (*BIGNUM, error) {
    // Pool get functionality mapping.
}

func (bn BIGNUM) zero() {
    // your reset code here
}

func (bn BIGNUM) flagsReset() {
    //clear statement for BN_FLG_CONSTTIME if leaked from previous frames 
}


Please note that we are assuming existence of methods like `poolGet()`, `zero()`, `flagsReset()` without having their specific contents.

Again, the answer should still be considered a high-level assumed mapping for actual context. Depending on the actual context of variables and methods, total structure and method mapping need to be considered differently.