Variant 1: In this variant, all hard-coded string literals are moved into a separate char const array. This allows all messages to be translated together and be fetched efficiently.

emit_ancillary_info (char const *program)
{
    char const* msg[] = {
        "\n%s online help: <%s>\n",
        "Report any translation bugs to "
        "<https://translationproject.org/team/>\n",
        "Full documentation <%s%s>\n",
        "or available locally via: info '(coreutils) %s%s'\n"
    };

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

    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf (_(msg[0]), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
        {
            fputs (_(msg[1]), stdout);
        }

    char const *url_program = STREQ (program, "[") ? "test" : program;

    printf (_(msg[2]),
            PACKAGE_URL, url_program);
    printf (_(msg[3]),
            node, node == program ? " invocation" : "");
}


Variant 2: In this variant, error handling has been updated to accomdate the scenario when the setlocale function returns a null pointer.

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
    char const *lc_messages;

    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages == nullptr)
        return;

    if ( STRNCMP_LIT (lc_messages, "en_"))
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
