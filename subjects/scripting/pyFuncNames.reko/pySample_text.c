// pySample_text.c
// Generated by decompiling pySample.dll
// using Reko decompiler version 0.9.4.0.

#include "pySample.h"

// 10001000: Register (ptr32 Eq_n) sum_wrapper(Stack (ptr32 Eq_n) ptrArg04, Stack (ptr32 Eq_n) ptrArg08)
PyObject * sum_wrapper(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_n = PyArg_ParseTuple(ptrArg08, "ii:sum", fp - 0x04, fp - 0x08);
	if (eax_n != null)
		return Py_BuildValue("i", dwLoc04 + dwLoc08);
	return eax_n;
}

// 10001050: Register (ptr32 Eq_n) dif_wrapper(Stack (ptr32 Eq_n) ptrArg04, Stack (ptr32 Eq_n) ptrArg08)
PyObject * dif_wrapper(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_n = PyArg_ParseTuple(ptrArg08, "ii:dif", fp - 0x08, fp - 0x04);
	if (eax_n != null)
		return Py_BuildValue("i", dwLoc08 - dwLoc04);
	return eax_n;
}

// 100010A0: Register (ptr32 Eq_n) div_wrapper(Stack (ptr32 Eq_n) ptrArg04, Stack (ptr32 Eq_n) ptrArg08)
PyObject * div_wrapper(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_n = PyArg_ParseTuple(ptrArg08, "ii:div", fp - 0x08, fp - 0x04);
	if (eax_n != null)
		return Py_BuildValue("i", (int32) ((int64) dwLoc08 /32 dwLoc04));
	return eax_n;
}

// 100010F0: Register (ptr32 Eq_n) fdiv_wrapper(Stack (ptr32 Eq_n) ptrArg04, Stack (ptr32 Eq_n) ptrArg08)
PyObject * fdiv_wrapper(PyObject * ptrArg04, PyObject * ptrArg08)
{
	PyObject * eax_n = PyArg_ParseTuple(ptrArg08, "ff:fdiv", fp - 0x08, fp - 0x04);
	if (eax_n != null)
		return Py_BuildValue("f", (real64) rLoc08 / (real64) rLoc04);
	return eax_n;
}

// 10001170: void initpySample()
void initpySample()
{
	// This is initialization of Python extension module
	Py_InitModule4("pySample", methods, null, null, 1007);
}

