/*!The Treasure Box Library
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
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author      ruki
 * @file        fixed_pool.c
 * @ingroup     memory
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * trace
 */
#define TB_TRACE_MODULE_NAME            "fixed_pool"
#define TB_TRACE_MODULE_DEBUG           (0)

/* //////////////////////////////////////////////////////////////////////////////////////
 * includes
 */
#include "fixed_pool.h"
#include "impl/static_fixed_pool.h"

/* //////////////////////////////////////////////////////////////////////////////////////
 * types
 */

/* //////////////////////////////////////////////////////////////////////////////////////
 * implementation
 */
tb_fixed_pool_ref_t tb_fixed_pool_init(tb_size_t slot_size, tb_size_t item_size, tb_fixed_pool_item_init_func_t item_init, tb_fixed_pool_item_exit_func_t item_exit, tb_cpointer_t priv)
{
    return tb_null;
}
tb_void_t tb_fixed_pool_exit(tb_fixed_pool_ref_t pool)
{
}
tb_size_t tb_fixed_pool_size(tb_fixed_pool_ref_t pool)
{
    return 0;
}
tb_void_t tb_fixed_pool_clear(tb_fixed_pool_ref_t pool)
{
}
tb_pointer_t tb_fixed_pool_malloc_(tb_fixed_pool_ref_t pool __tb_debug_decl__)
{
    return tb_null;
}
tb_pointer_t tb_fixed_pool_malloc0_(tb_fixed_pool_ref_t pool __tb_debug_decl__)
{
    return tb_null;
}
tb_bool_t tb_fixed_pool_free_(tb_fixed_pool_ref_t pool, tb_pointer_t item __tb_debug_decl__)
{
    return tb_false;
}
tb_void_t tb_fixed_pool_walk(tb_fixed_pool_ref_t pool, tb_fixed_pool_item_walk_func_t func, tb_cpointer_t priv)
{
}
tb_void_t tb_fixed_pool_dump(tb_fixed_pool_ref_t pool)
{
}
