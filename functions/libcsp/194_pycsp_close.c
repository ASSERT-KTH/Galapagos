static PyObject* pycsp_close(PyObject *self, PyObject *conn_capsule) {
    csp_conn_t * conn = get_obj_as_conn(conn_capsule, true);
    if (conn) {
        csp_close(conn);
        PyCapsule_SetPointer(conn_capsule, &CSP_POINTER_HAS_BEEN_FREED);
    }

    return Py_BuildValue("i", CSP_ERR_NONE);
}