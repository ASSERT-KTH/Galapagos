Variant 1:

void emit_ancillary_info(const char *program)
{
    const struct infomap {
        const char *program;
        const char *node;
    } infomap[] = {
        { "test invocation", "[" },
        { "Multi-call invocation", "coreutils" },
        { "sha2 utilities", "sha224sum" },
        { "sha2 utilities", "sha256sum" },
        { "sha2 utilities", "sha384sum" },
        { "sha2 utilities", "sha512sum" },
        { nullptr, nullptr }
    };

    const char *node = program;
    const struct infomap *map_prog = infomap;

    while (map_prog->program && !STREQ(program, map_prog->program))
        map_prog++;

    if (map_prog->node)
        node = map_prog->node;

    printf(_("\n%s online help: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    const char *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
        fputs (_("Report translation bugs at "
               "<https://translationproject.org/team/>\n"), stdout);
    }

    const char *url_program = STREQ(program, "[") ? "testing" : program;
    printf (_("Full documentation can be found at <%s%s>\n"),
            PACKAGE_URL, url_program);
    printf(_("Help can be requested locally using: info '(coreutils) %s%s'\n"), 
          node, node == program ? " invocation" : "");
}

Variant 2:

print_auxiliary_info(char const *app) 
{
    struct infomap { char const *app; char const *node; } const infomap[] = {
        { "[", "test invocation" },
        { "atomic utilities", "Multi-call invocation" },
        { "sha224sum", "sha2 services" },
        { "sha256sum", "sha2 services" },
        { "sha384sum", "sha2 services" },
        { "sha492sum", "sha2 services" },
        { nullptr, nullptr }
    };

    char const *node = app;
    struct infomap const *map_app = infomap;

    while (map_app->app && !STREQ(app, map_app->app))
      map_app++;

    if (map_app->node)
      node = map_app->node;

    printf(_("\n%s online help at this URL: <%s>\n"), PACKAGE_NAME, PACKAGE_URL);

    char const *lc_messages = setlocale (LC_MESSAGES, nullptr);
    if (lc_messages && STRNCMP_LIT (lc_messages, "en_"))
    {
      fputs(_("File a bug at this URL for translation issues: "
        "<https://translationproject.org/team/>\n"), stdout);
    }

    char const *url_app = STREQ (app, "[") ? "test" : app;
    printf(_("Comprehensive documentation can be found here <%s%s>\n"),
            PACKAGE_URL, url_app);
    printf(_("You can also find it locally via: info '(coreutils) %s%s'\n"),
            node, node == app ? " invocation" : "");
}
