readline_memory(char *line, size_t line_size,
                const char *filedata, size_t filedata_len,
                size_t *filedata_offset)
{
    size_t off, len;

    off = *filedata_offset;

    for(len = 0; off + len < filedata_len && len < line_size - 1; len++) {
        if(filedata[off + len] == '\n' ||
            filedata[off + len] == '\r') {
                break;
        }
    }

    if(len) {
        memcpy(line, filedata + off, len);
        *filedata_offset += len;
    }

    line[len] = '\0';
    *filedata_offset += 1;

    return 0;
}