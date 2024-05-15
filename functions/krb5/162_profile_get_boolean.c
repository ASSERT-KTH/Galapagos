profile_get_boolean(profile_t profile, const char *name, const char *subname,
                    const char *subsubname, int def_val, int *ret_boolean)
{
    char            *value;
    errcode_t       retval;
    const char      *names[4];

    if (profile == 0) {
        *ret_boolean = def_val;
        return 0;
    }

    names[0] = name;
    names[1] = subname;
    names[2] = subsubname;
    names[3] = 0;
    retval = profile_get_value(profile, names, &value);
    if (retval == PROF_NO_SECTION || retval == PROF_NO_RELATION) {
        *ret_boolean = def_val;
        return 0;
    } else if (retval)
        return retval;

    retval = profile_parse_boolean(value, ret_boolean);
    free(value);
    return retval;
}