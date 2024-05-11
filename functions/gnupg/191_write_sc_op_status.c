write_sc_op_status (gpg_error_t err)
{
  switch (gpg_err_code (err))
    {
    case 0:
      write_status (STATUS_SC_OP_SUCCESS);
      break;
#if GNUPG_MAJOR_VERSION != 1
    case GPG_ERR_CANCELED:
    case GPG_ERR_FULLY_CANCELED:
      write_status_text (STATUS_SC_OP_FAILURE, "1");
      break;
    case GPG_ERR_BAD_PIN:
    case GPG_ERR_BAD_RESET_CODE:
      write_status_text (STATUS_SC_OP_FAILURE, "2");
      break;
    case GPG_ERR_PIN_BLOCKED:
      write_status_text (STATUS_SC_OP_FAILURE, "3");
      break;
    case GPG_ERR_NO_RESET_CODE:
      write_status_text (STATUS_SC_OP_FAILURE, "4");
      break;
    default:
      write_status (STATUS_SC_OP_FAILURE);
      break;
#endif /* GNUPG_MAJOR_VERSION != 1 */
    }
}