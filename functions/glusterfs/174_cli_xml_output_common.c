cli_xml_output_common (xmlTextWriterPtr writer, int op_ret, int op_errno,
                       char *op_errstr)
{
        int             ret = -1;

        ret = xmlTextWriterWriteFormatElement (writer, (xmlChar *)"opRet",
                                               "%d", op_ret);
        XML_RET_CHECK_AND_GOTO (ret, out);

        ret = xmlTextWriterWriteFormatElement (writer, (xmlChar *)"opErrno",
                                               "%d", op_errno);
        XML_RET_CHECK_AND_GOTO (ret, out);

        ret = xmlTextWriterWriteFormatElement (writer, (xmlChar *)"opErrstr",
                                                "%s", op_errstr);
        XML_RET_CHECK_AND_GOTO (ret, out);

out:
        gf_log ("cli", GF_LOG_DEBUG, "Returning %d", ret);
        return ret;
}