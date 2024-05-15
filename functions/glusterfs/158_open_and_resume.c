open_and_resume (xlator_t *this, fd_t *fd, call_stub_t *stub)
{
	ob_fd_t  *ob_fd = NULL;
	int       op_errno = 0;

	if (!fd)
		goto nofd;

	LOCK (&fd->lock);
	{
		ob_fd = __ob_fd_ctx_get (this, fd);
		if (!ob_fd)
			goto unlock;

		if (ob_fd->op_errno) {
			op_errno = ob_fd->op_errno;
			goto unlock;
		}

		list_add_tail (&stub->list, &ob_fd->list);
	}
unlock:
	UNLOCK (&fd->lock);

nofd:
	if (op_errno)
		call_unwind_error (stub, -1, op_errno);
	else if (ob_fd)
		ob_fd_wake (this, fd);
	else
		call_resume (stub);

	return 0;
}