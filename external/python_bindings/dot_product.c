/* Python bindings for dot product example */

#include "Python.h"
#include "example.h"

/* Python binding for our dot_product function */
static PyObject *
dot_product_impl(PyObject *self, PyObject *args){
    std::array<float, 4> vec4_x;
    std::array<float, 4> vec4_y;
    if(!PyArg_ParseTuple(args, "(4)(4)", &vec4_x[0], &vec4_y[0])){
        return NULL;
    }
    result = dot_product(vec4_x, vec4_y);
    return Py_BuildValue("f", result);
}
/* Methods for our vector math object*/
static PyMethodDef VectorComputationMethods[] = {
    {"dot_product", dot_product_impl, METH_VARARGS, "Computes our dot product in C code"},
    {NULL, NULL, 0, NULL} /* End of methods sential value */
};
/* define the module */
static struct PyModuleDef vector_mathematics_module = {
    PyModuleDef_HEAD_INIT,
    "vector_module",
    -1,
    VectorComputationMethods
};

/* Init code */
PyMODINIT_FUNC
PyInit_demo_module(void){
    return PyModule_Create(&vector_mathematics_module);
}
