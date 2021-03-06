/*
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2016 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef ZEND_TYPES_H
#define ZEND_TYPES_H

typedef unsigned char zend_bool; /* 无符号布尔类型 */
typedef unsigned char zend_uchar; /* 无符号字符类型 */
typedef unsigned int zend_uint; /* 无符号整数类型 */
typedef unsigned long zend_ulong; /* 无符号长整数类型 */
typedef unsigned short zend_ushort; /* 无符号短整数类型 */

#define HAVE_ZEND_LONG64
#ifdef ZEND_WIN32
typedef __int64 zend_long64;
typedef unsigned __int64 zend_ulong64;
#elif SIZEOF_LONG_LONG_INT == 8
typedef long long int zend_long64;
typedef unsigned long long int zend_ulong64;
#elif SIZEOF_LONG_LONG == 8
typedef long long zend_long64;
typedef unsigned long long zend_ulong64;
#else
# undef HAVE_ZEND_LONG64
#endif

#ifdef _WIN64
typedef __int64 zend_intptr_t;
typedef unsigned __int64 zend_uintptr_t;
#else
typedef long zend_intptr_t;
typedef unsigned long zend_uintptr_t;
#endif

typedef unsigned int zend_object_handle;
typedef struct _zend_object_handlers zend_object_handlers;
typedef struct _zval_struct zval;

typedef struct _zend_object_value {
	zend_object_handle handle;/* unsigned int类型 EG(objects_store).object_buckets 的索引 */
	const zend_object_handlers *handlers;
} zend_object_value;

#endif /* ZEND_TYPES_H */

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
