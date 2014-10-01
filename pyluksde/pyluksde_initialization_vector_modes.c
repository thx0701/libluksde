/*
 * Python object definition of the libluksde initialization vector modes
 *
 * Copyright (C) 2013-2014, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( HAVE_WINAPI )
#include <stdlib.h>
#endif

#include "pyluksde_initialization_vector_modes.h"
#include "pyluksde_libluksde.h"
#include "pyluksde_python.h"
#include "pyluksde_unused.h"

PyTypeObject pyluksde_initialization_vector_modes_type_object = {
	PyObject_HEAD_INIT( NULL )

	/* ob_size */
	0,
	/* tp_name */
	"pyluksde.initialization_vector_modes",
	/* tp_basicsize */
	sizeof( pyluksde_initialization_vector_modes_t ),
	/* tp_itemsize */
	0,
	/* tp_dealloc */
	(destructor) pyluksde_initialization_vector_modes_free,
	/* tp_print */
	0,
	/* tp_getattr */
	0,
	/* tp_setattr */
	0,
	/* tp_compare */
	0,
	/* tp_repr */
	0,
	/* tp_as_number */
	0,
	/* tp_as_sequence */
	0,
	/* tp_as_mapping */
	0,
	/* tp_hash */
	0,
	/* tp_call */
	0,
	/* tp_str */
	0,
	/* tp_getattro */
	0,
	/* tp_setattro */
	0,
	/* tp_as_buffer */
	0,
	/* tp_flags */
	Py_TPFLAGS_DEFAULT,
	/* tp_doc */
	"pyluksde initialization vector modes object (wraps LIBLUKSDE_INITIALIZATION_VECTOR_MODES)",
	/* tp_traverse */
	0,
	/* tp_clear */
	0,
	/* tp_richcompare */
	0,
	/* tp_weaklistoffset */
	0,
	/* tp_iter */
	0,
	/* tp_iternext */
	0,
	/* tp_methods */
	0,
	/* tp_members */
	0,
	/* tp_getset */
	0,
	/* tp_base */
	0,
	/* tp_dict */
	0,
	/* tp_descr_get */
	0,
	/* tp_descr_set */
	0,
	/* tp_dictoffset */
	0,
	/* tp_init */
	(initproc) pyluksde_initialization_vector_modes_init,
	/* tp_alloc */
	0,
	/* tp_new */
	0,
	/* tp_free */
	0,
	/* tp_is_gc */
	0,
	/* tp_bases */
	NULL,
	/* tp_mro */
	NULL,
	/* tp_cache */
	NULL,
	/* tp_subclasses */
	NULL,
	/* tp_weaklist */
	NULL,
	/* tp_del */
	0
};

/* Initializes the type object
 * Returns 1 if successful or -1 on error
 */
int pyluksde_initialization_vector_modes_init_type(
     PyTypeObject *type_object )
{
	if( type_object == NULL )
	{
		return( -1 );
	}
	type_object->tp_dict = PyDict_New();

	if( type_object->tp_dict == NULL )
	{
		return( -1 );
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "BENBI",
	     PyInt_FromLong(
	      LIBLUKSDE_INITIALIZATION_VECTOR_MODE_BENBI ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "ESSIV",
	     PyInt_FromLong(
	      LIBLUKSDE_INITIALIZATION_VECTOR_MODE_ESSIV ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "LMK",
	     PyInt_FromLong(
	      LIBLUKSDE_INITIALIZATION_VECTOR_MODE_LMK ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "NULL",
	     PyInt_FromLong(
	      LIBLUKSDE_INITIALIZATION_VECTOR_MODE_NULL ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "PLAIN32",
	     PyInt_FromLong(
	      LIBLUKSDE_INITIALIZATION_VECTOR_MODE_PLAIN32 ) ) != 0 )
	{
		goto on_error;
	}
	if( PyDict_SetItemString(
	     type_object->tp_dict,
	     "PLAIN64",
	     PyInt_FromLong(
	      LIBLUKSDE_INITIALIZATION_VECTOR_MODE_PLAIN64 ) ) != 0 )
	{
		goto on_error;
	}
	return( 1 );

on_error:
	if( type_object->tp_dict != NULL )
	{
		Py_DecRef(
		 type_object->tp_dict );

		type_object->tp_dict = NULL;
	}
	return( -1 );
}

/* Creates a new initialization vector_modes object
 * Returns a Python object if successful or NULL on error
 */
PyObject *pyluksde_initialization_vector_modes_new(
           void )
{
	pyluksde_initialization_vector_modes_t *pyluksde_initialization_vector_modes = NULL;
	static char *function                                                        = "pyluksde_initialization_vector_modes_new";

	pyluksde_initialization_vector_modes = PyObject_New(
	                                        struct pyluksde_initialization_vector_modes,
	                                        &pyluksde_initialization_vector_modes_type_object );

	if( pyluksde_initialization_vector_modes == NULL )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize initialization vector modes.",
		 function );

		goto on_error;
	}
	if( pyluksde_initialization_vector_modes_init(
	     pyluksde_initialization_vector_modes ) != 0 )
	{
		PyErr_Format(
		 PyExc_MemoryError,
		 "%s: unable to initialize initialization vector modes.",
		 function );

		goto on_error;
	}
	return( (PyObject *) pyluksde_initialization_vector_modes );

on_error:
	if( pyluksde_initialization_vector_modes != NULL )
	{
		Py_DecRef(
		 (PyObject *) pyluksde_initialization_vector_modes );
	}
	return( NULL );
}

/* Intializes a initialization vector modes object
 * Returns 0 if successful or -1 on error
 */
int pyluksde_initialization_vector_modes_init(
     pyluksde_initialization_vector_modes_t *pyluksde_initialization_vector_modes )
{
	static char *function = "pyluksde_initialization_vector_modes_init";

	if( pyluksde_initialization_vector_modes == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid initialization vector modes.",
		 function );

		return( -1 );
	}
	return( 0 );
}

/* Frees a initialization vector modes object
 */
void pyluksde_initialization_vector_modes_free(
      pyluksde_initialization_vector_modes_t *pyluksde_initialization_vector_modes )
{
	static char *function = "pyluksde_initialization_vector_modes_free";

	if( pyluksde_initialization_vector_modes == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid initialization vector modes.",
		 function );

		return;
	}
	if( pyluksde_initialization_vector_modes->ob_type == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid initialization vector modes - missing ob_type.",
		 function );

		return;
	}
	if( pyluksde_initialization_vector_modes->ob_type->tp_free == NULL )
	{
		PyErr_Format(
		 PyExc_TypeError,
		 "%s: invalid initialization vector modes - invalid ob_type - missing tp_free.",
		 function );

		return;
	}
	pyluksde_initialization_vector_modes->ob_type->tp_free(
	 (PyObject*) pyluksde_initialization_vector_modes );
}
