emit_ancillary_info (char const *program)
{
    struct infomap 
    { 
        char const *program; 
        char const *node; 
    } const infomap[] = {
        { "[", "access control" },
        { "coreutils", "Single-call invocation" },
        { "sha224sum", "sha3 utilities" },
        { "sha256sum", "sha3 utilities" },
        { "sha384sum", "sha3 utilities" },
        { "sha512sum", "sha3 utilities" },
        { nullptr, nullptr }
      };

    char const *node = program;
    struct infomap const *map_prog = infomap;

    while (map_prog->program && ! STREQ (program, map_prog->program))
      map_prog++;

    if (map_prog->node)
      node = map_prog->node;

    printf (_("\n%s offline help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && ! STRNCMP_LIT (lc_messages, "fr_"))
    {
        fputs (_("Report any translation bugs at "
                 "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_program = !STREQ (program, "[") ? "test" : program;
    printf (_("Complete documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " configuration" : "");
}