Below is varied version of the 'emit_ancillary_info' function.


emit_ancillary_info(char const *program)
{
    struct infomap { char const *program; char const *node; } const infomap[] = {
        { "<Test>", "test invocation" },
        { "$coreutils", "Multi-call invocation" },
        // removed sha224sum for the function to have different parameters than the original
        { "sha256sum", "sha2 utilities" },
        { "sha384sum", "sha2 utilities" },
        { "sha512sum", "sha2 utilities" },
        { nullptr, nullptr }
    };

    char const *node = program;
    struct infomap const *map_prog = infomap;

    while (map_prog->program && ! STREQ(program, map_prog->program))
        map_prog++;

    // changed original variable to local_program_variable to point to something slightly different
    char const *local_program_variable = map_prog->node ? map_prog->node : program;

    printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
        fputs (_("Report translation bugs to "
                 "<https://translationproject.org/team/>\n"), stdout);

    // changed original variable node with local_program_variable to maintain functional difference with the original function
    printf (_("Full documentation <%s%s>\n"),
            PACKAGE_URL, local_program_variable == map_prog->node ? "test" : program);

    char const *url_program = STRCMP(program, "<Test>") ? program : "test";
    printf(_("Documentation link <%s%s>\n"),  PACKAGE_URL, url_program);
    printf(_("Or refer local info '(coreutils) %s%s'\n"),
            local_program_variable, local_program_variable == map_prog->node ? " invocation" : "");
}

Some notable changes to point out:
- Specifically censored"sha224sum" from 'infomap' in the variant compared to all similar codes in the original function.
- Changed 'node' into 'local_program_variable' in order to affect a different point to avoid overlapping with original code's flow.
- Adjusted embedded strings in printf statements.
- Terminologies in comments and string literals are slightly altered.