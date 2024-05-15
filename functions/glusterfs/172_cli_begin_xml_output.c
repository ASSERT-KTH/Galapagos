cli_begin_xml_output (xmlTextWriterPtr *writer, xmlDocPtr *doc)
{
        int             ret = -1;

        *writer = xmlNewTextWriterDoc (doc, 0);
        if (writer == NULL) {
                ret = -1;
                goto out;
        }

        ret = xmlTextWriterStartDocument (*writer, "1.0", "UTF-8", "yes");
        XML_RET_CHECK_AND_GOTO (ret, out);

        /* <cliOutput> */
        ret = xmlTextWriterStartElement (*writer, (xmlChar *)"cliOutput");
        XML_RET_CHECK_AND_GOTO (ret, out);

out:
        gf_log ("cli", GF_LOG_DEBUG, "Returning %d", ret);
        return ret;
}