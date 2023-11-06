emit_ancillary_info (char const *program)
{
    struct infomap { char const *program; char const *node; } const infomap[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
      };

    char const *node = program;
    struct infomap const *map_prog = infomap;

    while (map_prog->program != nullptr && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node != nullptr)
        node = map_prog->node;

   printf (_("\nInfo for %s: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);

    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
        fputs (_("Please report translation bugs to: "
                 "<https://translationproject.org/team/>\n"), stdout);

    char const *url_program = STREQ (program, "[") ? "test" : program;
    printf (_("See full documentation at <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf (_("or check locally: info '(coreutils)%s%s'\n"),
            node, node == program ? " usage" : "");
}