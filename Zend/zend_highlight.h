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

#ifndef ZEND_HIGHLIGHT_H
#define ZEND_HIGHLIGHT_H
/* 高亮代码的颜色 */
#define HL_COMMENT_COLOR     "#FF8000"    /* orange */ 
#define HL_DEFAULT_COLOR     "#0000BB"    /* blue */
#define HL_HTML_COLOR        "#000000"    /* black */
#define HL_STRING_COLOR      "#DD0000"    /* red */
#define HL_KEYWORD_COLOR     "#007700"    /* green */


typedef struct _zend_syntax_highlighter_ini {/* 代码高亮的各种颜色结构体 */
	char *highlight_html;
	char *highlight_comment;
	char *highlight_default;
	char *highlight_string;
	char *highlight_keyword;
} zend_syntax_highlighter_ini;


BEGIN_EXTERN_C()
ZEND_API void zend_highlight(zend_syntax_highlighter_ini *syntax_highlighter_ini TSRMLS_DC);
ZEND_API void zend_strip(TSRMLS_D); /* strip剥除的意思，很明显，该函数是去除PHP代码无效内容 */
ZEND_API int highlight_file(char *filename, zend_syntax_highlighter_ini *syntax_highlighter_ini TSRMLS_DC);
ZEND_API int highlight_string(zval *str, zend_syntax_highlighter_ini *syntax_highlighter_ini, char *str_name TSRMLS_DC);
ZEND_API void zend_html_putc(char c); /* 该函数是为了转换特殊的HTML字符，例如空格转成HTML的&nbsp; */
ZEND_API void zend_html_puts(const char *s, uint len TSRMLS_DC); /* 将字符串转义成HTML文本 */
END_EXTERN_C()

extern zend_syntax_highlighter_ini syntax_highlighter_ini;

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
