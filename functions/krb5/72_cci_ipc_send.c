cc_int32 cci_ipc_send (enum cci_msg_id_t  in_request_name,
                       cci_identifier_t   in_identifier,
                       k5_ipc_stream       in_request_data,
                       k5_ipc_stream      *out_reply_data)
{
    return cci_check_error (_cci_ipc_send (in_request_name, 1,
                                           in_identifier,
                                           in_request_data,
                                           out_reply_data));
}