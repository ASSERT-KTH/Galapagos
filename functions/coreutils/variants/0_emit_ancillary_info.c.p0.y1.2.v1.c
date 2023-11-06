void emit_ancillary_info (char const *program)
{
    typedef struct { char const *program; char const *node; } infotype;
    static const infotype info[] =
    {
        {"[", "test invocation"},
        {"coreutils", "Multi-call invocation"},
        {"sha224sum", "sha2 utilities"},
        {"sha256sum", "sha2 utilities"},
        {"sha384sum", "sha2 utilities"},
        {"sha512sum", "sha2 utilities"},
        {0, 0}
    };

    char const *node = program;
    infotype const *program_map = info;

    while (program_map->program && ! STREQ (program, program_map->program))
        program_map++;

    if (program_map->node)
    node= program_map->node;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *locale_messages = setlocale(LC_MESSAGES, 0);
    if (locale_messages && STRNCMP_LIT (locale_messages, "en_"))
    {
        fputs (_("Report translation issues to "
               "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *program_url= STREQ (program, "[") ? "test" : program;

    printf (_("Complete documentation <%s%s>\n"),
          PACKAGE_URL, program_url);

    printf (_("Or accessible locally via: info '(coreutils) %s%s'\n"),
          node, node == program ? " invocation" : "");
}