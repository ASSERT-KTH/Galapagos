Here is a variant of the function which adds additional information to the infomap, included in specific program cases, and also a tailor-made output for when it's certain language locale is detected other than the hardcoded "en_" prefix.

void emit_ancillary_info(char const *program) {
    struct infomap { char const *program; char const *node; } const infomap[] = {
        { "[", "test invocation" },
        { "coreutils", "Multi-call invocation" },
        { "sha224sum", "sha2 utilities" },
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { "new_program","New Program Info"},
        { nullptr, nullptr }
    };

    char const *node = program;
    struct infomap const *map_prog = infomap;

    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf (_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
        fputs (_("Report any translation bugs to "
                 "<https://translationproject.org/team/>\n"), stdout);
    }

    // Tailor-made output when locale is "fr_FR" as an example:
    if (lc_messages && STRNCMP_LIT (lc_messages, "fr_FR"))
    {
        fputs (_("\nPour signaler des bugs de traduction, veuillez visiter"
                 " <https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_program = STREQ (program, "[") ? "test" : program;
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf (_("or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " invocation" : "");
}

This version adds an entry `"new_program","New Program Info"` to `infomap` and also provides a specific translation instructions output to French locals (`"fr_FR"`).