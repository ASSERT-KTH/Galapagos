getenv(name)
    char *name;
{
    int offset;

    return(_findenv(name, &offset));
}