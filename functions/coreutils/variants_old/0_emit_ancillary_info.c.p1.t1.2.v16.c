
emit_ancillary_info (char const *program)
{
    struct infomap { char const *program; char const *node; } const infomap[] = {
        { "ls", "ls invocation" },
        { "sha1sum", "sha1 utilities" },
        { "coreutils", "Multi-duty handling" },
        { "xargs", "xargs usage" },
        { nullptr, nullptr }
    };

    char const *node = program;
    struct infomap const *map_prog = infomap;

    while (map_prog->program && !STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
        fputs (_("Translation issues can be reported at "
                "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_program = STREQ (program, "[") ? "testing" : program;
    printf (_("Complete documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf (_("Available in local document via: inte '(coreutils) %s%s'\n"),
            node, node == program ? " guideline" : "");
}

Modifications from the original:

- Different strings in structured array (infomap), illustration can be customized and integrated with existing information layout.
- Changing some of the printed messages presented to suite adjustments in functionality.
- There’s a minor modification with existing variable “url_program”: to be more illustrative, "test" is now updated to "testing".