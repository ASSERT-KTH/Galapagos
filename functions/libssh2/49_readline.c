readline(char *line, int line_size, FILE * fp)
{
    size_t len;

    if(!line) {
        return -1;
    }
    if(!fgets(line, line_size, fp)) {
        return -1;
    }

    if(*line) {
        len = strlen(line);
        if(len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
    }

    if(*line) {
        len = strlen(line);
        if(len > 0 && line[len - 1] == '\r') {
            line[len - 1] = '\0';
        }
    }

    return 0;
}