fail_if(int condition, const char *name)
{
    if (condition) {
        fprintf(stderr, "%s failed\n", name);
        exit(1);
    }
}