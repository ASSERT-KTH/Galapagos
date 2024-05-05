static PyObject* pycsp_accept(PyObject *self, PyObject *args) {
    PyObject* socket_capsule;
    uint32_t timeout = CSP_MAX_TIMEOUT;
    if (!PyArg_ParseTuple(args, "O|I", &socket_capsule, &timeout)) {
        return NULL; // TypeError is thrown
    }
    csp_socket_t* socket = get_obj_as_socket(socket_capsule, false);
    if (socket == NULL) {
        return NULL;
    }
    csp_conn_t* conn;
    Py_BEGIN_ALLOW_THREADS;
    conn = csp_accept(socket, timeout);
    Py_END_ALLOW_THREADS;
    if (conn == NULL) {
        Py_RETURN_NONE; // timeout -> None
    }

    return PyCapsule_New(conn, CONNECTION_CAPSULE, pycsp_free_csp_conn);
}