/*
 * Sector data functions
 *
 * Copyright (C) 2013-2019, Joachim Metz <joachim.metz@gmail.com>
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

#if !defined( _LIBLUKSDE_SECTOR_DATA_H )
#define _LIBLUKSDE_SECTOR_DATA_H

#include <common.h>
#include <types.h>

#include "libluksde_encryption.h"
#include "libluksde_io_handle.h"
#include "libluksde_libbfio.h"
#include "libluksde_libcerror.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libluksde_sector_data libluksde_sector_data_t;

struct libluksde_sector_data
{
	/* The encrypted data
	 */
	uint8_t *encrypted_data;

	/* The data
	 */
	uint8_t *data;

	/* The data size
	 */
	size_t data_size;
};

int libluksde_sector_data_initialize(
     libluksde_sector_data_t **sector_data,
     size_t data_size,
     libcerror_error_t **error );

int libluksde_sector_data_free(
     libluksde_sector_data_t **sector_data,
     libcerror_error_t **error );

int libluksde_sector_data_read(
     libluksde_sector_data_t *sector_data,
     libluksde_io_handle_t *io_handle,
     libbfio_handle_t *file_io_handle,
     off64_t sector_data_offset,
     libluksde_encryption_context_t *encryption_context,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif /* !defined( _LIBLUKSDE_SECTOR_DATA_H ) */

