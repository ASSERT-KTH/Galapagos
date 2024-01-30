There is no direct translation of this C function into Go, because Go handles strings and character arrays differently than C does. Go does not have a string rotation operator like '+=', nor does it support redirecting a string pointer like '*args'. Instead, strings are held in a read-only slice of bytes. I can make a similar function though, where it tries to match the start of the provided string with the provided substring but the functionality will not be identical because C-like string pointer manipulations are not supported in GoLang in the same way.

go
func nextarg(args *string, str string) bool {
    if args == nil {
        return false
    } else {
        r:=strings.HasPrefix(*args, str)
        if r {
            *args = strings.TrimPrefix(*args, str)
        }
    return r;
    }
}
