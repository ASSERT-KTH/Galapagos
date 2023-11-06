void emit_ancillary_info (char const *program)
{
    struct infomap { char const *pgm_name; char const *pgm_node; } const infomap_data[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
    };

    char const * node = program;
    struct infomap const * info_prog = infomap_data;

    while (info_prog->pgm_name && ! STREQ (program, info_prog->pgm_name))
        info_prog++;

    if (info_prog->pgm_node)
        node = info_prog->pgm_node;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *locale_messages = setlocale (LC_MESSAGES, nullptr);
    if (locale_messages && STRNCMP_LIT (locale_messages, "en_"))
    {
        fputs (_("Report any translation bugs to "
                 "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_program = STREQ (program, "[") ? "test" : program;
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " invocation" : "");
}