#include <Python.h>

void call_python_function() {
    Py_Initialize();
    PyObject* py_module = PyImport_ImportModule("math_utils");
    PyObject* py_func = PyObject_GetAttrString(py_module, "calculate_square_root");
    PyObject* args = PyTuple_Pack(1, PyFloat_FromDouble(64.0));
    PyObject* result = PyObject_CallObject(py_func, args);
    printf("Result: %f\n", PyFloat_AsDouble(result));
    Py_Finalize();
}

#include <Python.h>

void call_python_function() {
    Py_Initialize();
    PyObject *module = PyImport_ImportModule("math_utils");
    PyObject *func = PyObject_GetAttrString(module, "square_root");
    PyObject *args = PyTuple_Pack(1, PyLong_FromLong(16));
    PyObject *result = PyObject_CallObject(func, args);

    long value = PyLong_AsLong(result);
    printf("Square Root: %ld\n", value);

    Py_Finalize();
}
