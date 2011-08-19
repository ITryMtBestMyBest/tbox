/*!The Tiny Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2011, ruki All rights reserved.
 *
 * \author		ruki
 * \file		uint64.c
 *
 */
/* ////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "uint64.h"

/* ////////////////////////////////////////////////////////////////////////
 * globals 
 */

#ifndef TB_CONFIG_TYPE_INT64
tb_uint64_t const g_uint64_zero = {0, 0};
tb_uint64_t const g_uint64_one 	= {0, 1};
#endif

/* ////////////////////////////////////////////////////////////////////////
 * implemention
 */
