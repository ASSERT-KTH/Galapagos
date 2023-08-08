The C function has the same original functionalilty with a slight change in its behavior in that it writes the output to a character array 'output_str' instead of standard output. 


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

    while (map_prog->program && ! STREQ (program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    char output_str[1000] = {0};
    sprintf(output_str,"\n%s online help: <%s>\n", PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
        {
          sprintf(output_str+strlen(output_str), _("Report any translation bugs to "
                   "<https://translationproject.org/team/>\n"));
        }

    char const *url_program = STREQ (program, "[") ? "test" : program;
    sprintf(output_str+strlen(output_str), _("Full documentation <%s%s>\n"),
            PACKAGE_URL, url_program);
    sprintf(output_str+strlen(output_str), _("or available locally via: info '(coreutils) %s%s'\n"),
            node, node == program ? " invocation" : "");

    fputs(output_str, stdout);
}
