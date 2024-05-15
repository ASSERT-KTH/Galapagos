void qstring_append(QString *qstring, const char *str)
{
    size_t len = strlen(str);

    capacity_increase(qstring, len);
    memcpy(qstring->string + qstring->length, str, len);
    qstring->length += len;
    qstring->string[qstring->length] = 0;
}