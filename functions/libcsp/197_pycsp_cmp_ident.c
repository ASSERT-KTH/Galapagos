static PyObject* pycsp_cmp_ident(PyObject *self, PyObject *args) {
    uint8_t node;
    uint32_t timeout = 1000;
    if (!PyArg_ParseTuple(args, "b|i", &node, &timeout)) {
        return NULL; // TypeError is thrown
    }

    struct csp_cmp_message msg;
    memset(&msg, 0, sizeof(msg));
    int res;
    Py_BEGIN_ALLOW_THREADS;
    res = csp_cmp_ident(node, timeout, &msg);
    Py_END_ALLOW_THREADS;
    if (res != CSP_ERR_NONE) {
        return PyErr_Error("csp_cmp_ident()", res);
    }
    return Py_BuildValue("isssss",
                         res,
                         msg.ident.hostname,
                         msg.ident.model,
                         msg.ident.revision,
                         msg.ident.date,
                         msg.ident.time);
}