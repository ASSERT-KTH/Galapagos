cli_end_xml_output (xmlTextWriterPtr writer, xmlDocPtr doc)
{
        int             ret = -1;

        /* </cliOutput> */
        ret = xmlTextWriterEndElement (writer);
        XML_RET_CHECK_AND_GOTO (ret, out);

        ret = xmlTextWriterEndDocument (writer);
        XML_RET_CHECK_AND_GOTO (ret, out);


        /* Dump xml document to stdout and pretty format it */
        xmlSaveFormatFileEnc ("-", doc, "UTF-8", 1);

        xmlFreeTextWriter (writer);
        xmlFreeDoc (doc);

out:
        gf_log ("cli", GF_LOG_DEBUG, "Returning %d", ret);
        return ret;
}