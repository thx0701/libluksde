/*
 * Volume functions
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

#if !defined( _LIBLUKSDE_INTERNAL_VOLUME_H )
#define _LIBLUKSDE_INTERNAL_VOLUME_H

#include <common.h>
#include <types.h>

#include "libluksde_extern.h"
#include "libluksde_io_handle.h"
#include "libluksde_libbfio.h"
#include "libluksde_libcerror.h"
#include "libluksde_libfcache.h"
#include "libluksde_libfdata.h"
#include "libluksde_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libluksde_internal_volume libluksde_internal_volume_t;

struct libluksde_internal_volume
{
	/* The current (storage media) offset
	 */
	off64_t current_offset;

	/* The sectors vector
	 */
	libfdata_vector_t *sectors_vector;

	/* The sectors cache
	 */
	libfcache_cache_t *sectors_cache;

	/* The file IO handle
	 */
	libbfio_handle_t *file_io_handle;

	/* The IO handle
	 */
	libluksde_io_handle_t *io_handle;

	/* Value to indicate if the file IO handle was created inside the library
	 */
	uint8_t file_io_handle_created_in_library;

	/* Value to indicate if the file IO handle was opened inside the library
	 */
	uint8_t file_io_handle_opened_in_library;
};

LIBLUKSDE_EXTERN \
int libluksde_volume_initialize(
     libluksde_volume_t **volume,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_free(
     libluksde_volume_t **volume,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_signal_abort(
     libluksde_volume_t *volume,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_open(
     libluksde_volume_t *volume,
     const char *filename,
     int access_flags,
     libcerror_error_t **error );

#if defined( HAVE_WIDE_CHARACTER_TYPE )
LIBLUKSDE_EXTERN \
int libluksde_volume_open_wide(
     libluksde_volume_t *volume,
     const wchar_t *filename,
     int access_flags,
     libcerror_error_t **error );
#endif

LIBLUKSDE_EXTERN \
int libluksde_volume_open_file_io_handle(
     libluksde_volume_t *volume,
     libbfio_handle_t *file_io_handle,
     int access_flags,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_close(
     libluksde_volume_t *volume,
     libcerror_error_t **error );

int libluksde_volume_open_read(
     libluksde_internal_volume_t *internal_volume,
     libbfio_handle_t *file_io_handle,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
ssize_t libluksde_volume_read_buffer(
         libluksde_volume_t *volume,
         void *buffer,
         size_t buffer_size,
         libcerror_error_t **error );

LIBLUKSDE_EXTERN \
ssize_t libluksde_volume_read_buffer_at_offset(
         libluksde_volume_t *volume,
         void *buffer,
         size_t buffer_size,
         off64_t offset,
         libcerror_error_t **error );

#ifdef TODO
LIBLUKSDE_EXTERN \
ssize_t libluksde_volume_write_buffer(
         libluksde_volume_t *volume,
         void *buffer,
         size_t buffer_size,
         libcerror_error_t **error );

LIBLUKSDE_EXTERN \
ssize_t libluksde_volume_write_buffer_at_offset(
         libluksde_volume_t *volume,
         const void *buffer,
         size_t buffer_size,
         off64_t offset,
         libcerror_error_t **error );
#endif

LIBLUKSDE_EXTERN \
off64_t libluksde_volume_seek_offset(
         libluksde_volume_t *volume,
         off64_t offset,
         int whence,
         libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_get_offset(
     libluksde_volume_t *volume,
     off64_t *offset,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_get_size(
     libluksde_volume_t *volume,
     size64_t *size,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_get_encryption_method(
     libluksde_volume_t *volume,
     int *encryption_method,
     int *encryption_chaining_mode,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_set_keys(
     libluksde_volume_t *volume,
     const uint8_t *master_key,
     size_t master_key_size,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_set_utf8_password(
     libluksde_volume_t *volume,
     const uint8_t *utf8_string,
     size_t utf8_string_length,
     libcerror_error_t **error );

LIBLUKSDE_EXTERN \
int libluksde_volume_set_utf16_password(
     libluksde_volume_t *volume,
     const uint16_t *utf16_string,
     size_t utf16_string_length,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
