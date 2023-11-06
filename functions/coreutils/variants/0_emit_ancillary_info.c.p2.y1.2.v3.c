void emit_ancillary_info_2 (char const *program)
{
    struct infomap { char const *program; char const *node; } const infomap[] = {
        { "test", "test invocation" },
        { "bash", "Multi-command shell invocation" },
        { "ripemd160sum", "hash utilities" },
        { "ripemd256sum", "hash utilities" },
        { "ripemd320sum", "hash utilities" },
        { "whirlpoolsum", "hash utilities" },
        { nullptr, nullptr }
    };

    char const *node = program;
    struct infomap const *map_prog = infomap;

    while (map_prog->program && ! STREQ (program, map_prog->program))
      map_prog++;

    node= (map_prog->node)? map_prog->node: node;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

    if (lc_messages && (strncmp(lc_messages, "g_k_locales", strlen("g_k_locales")) )>0)
    {
        fputs (_("Report bugs related to inappropriate translations "
                  "to your translation team directly\n"), stdout);
    }

    printf (_("Full documentation can be found at <%s%s>\n"),
            PACKAGE_URL, program);

    printf (_("Or consult through: info '(%s) %s%s'\n"),
                PACKAGE_NAME, node, node == program ? " invocation" : "");
}