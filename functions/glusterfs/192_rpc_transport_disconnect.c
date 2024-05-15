rpc_transport_disconnect (rpc_transport_t *this)
{
	int32_t ret = -1;

	GF_VALIDATE_OR_GOTO("rpc_transport", this, fail);

	ret = this->ops->disconnect (this);
fail:
	return ret;
}