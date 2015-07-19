/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2015 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author:                                                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "ext/standard/info.h"
#include "php_php_ext_example.h"

/* If you declare any globals in php_php_ext_example.h uncomment this:
ZEND_DECLARE_MODULE_GLOBALS(php_ext_example)
*/

/* True global resources - no need for thread safety here */
static int le_php_ext_example;

php_class_entry *php_ext_example_class_entry;

/* {{{ PHP_INI
 */
/* Remove comments and fill if you need to have entries in php.ini
PHP_INI_BEGIN()
    STD_PHP_INI_ENTRY("php_ext_example.global_value",      "42", PHP_INI_ALL, OnUpdateLong, global_value, zend_php_ext_example_globals, php_ext_example_globals)
    STD_PHP_INI_ENTRY("php_ext_example.global_string", "foobar", PHP_INI_ALL, OnUpdateString, global_string, zend_php_ext_example_globals, php_ext_example_globals)
PHP_INI_END()
*/
/* }}} */

/* Remove the following function when you have successfully modified config.m4
   so that your module can be compiled into PHP, it exists only for testing
   purposes. */

/* Every user-visible function in PHP should document itself in the source */
/* {{{ proto string confirm_php_ext_example_compiled(string arg)
   Return a string to confirm that the module is compiled in */
PHP_FUNCTION(confirm_php_ext_example_compiled)
{
	char *arg = NULL;
	int arg_len, len;
	char *strg;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &arg, &arg_len) == FAILURE) {
		return;
	}

	len = spprintf(&strg, 0, "Congratulations! You have successfully modified ext/%.78s/config.m4. Module %.78s is now compiled into PHP.", "php_ext_example", arg);
	RETURN_STRINGL(strg, len, 0);
}
/* }}} */
/* The previous line is meant for vim and emacs, so it can correctly fold and
   unfold functions in source code. See the corresponding marks just before
   function definition, where the functions purpose is also documented. Please
   follow this convention for the convenience of others editing your code.
*/

PHP_FUNCTION(self_concat)
{
	char *str = NULL;
    int argc = ZEND_NUM_ARGS();
    int str_len;
    long n;
    char *result;
    char *ptr;
    int result_length;

    if (zend_parse_parameters(argc TSRMLS_CC, "sl", &str, &str_len, &n) == FAILURE)
        return;

    result_length = (str_len * n);
    result = (char *) emalloc(result_length + 1);
    ptr = result;

    while (n--) {
        memcpy(ptr, str, str_len);
        ptr += str_len;
    }

    ptr = '\0';
    RETURN_STRINGL(result, result_length, 0);
}


/* {{{ php_php_ext_example_init_globals
 */
/* Uncomment this function if you have INI entries
static void php_php_ext_example_init_globals(zend_php_ext_example_globals *php_ext_example_globals)
{
	php_ext_example_globals->global_value = 0;
	php_ext_example_globals->global_string = NULL;
}
*/
/* }}} */

/* {{{ PHP_MINIT_FUNCTION
 */
PHP_MINIT_FUNCTION(php_ext_example)
{
	/* If you have INI entries, uncomment these lines
	REGISTER_INI_ENTRIES();
	*/
	zend_class_entry *temp_ce;
	INIT_CLASS_ENTRY(temp_ce, "SampleClass", php_ext_example_functions);
	php_ext_example_class_entry = zend_register_internal_class(&temp_ce, TSRMLS_CC);
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MSHUTDOWN_FUNCTION
 */
PHP_MSHUTDOWN_FUNCTION(php_ext_example)
{
	/* uncomment this line if you have INI entries
	UNREGISTER_INI_ENTRIES();
	*/
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request start */
/* {{{ PHP_RINIT_FUNCTION
 */
PHP_RINIT_FUNCTION(php_ext_example)
{
	return SUCCESS;
}
/* }}} */

/* Remove if there's nothing to do at request end */
/* {{{ PHP_RSHUTDOWN_FUNCTION
 */
PHP_RSHUTDOWN_FUNCTION(php_ext_example)
{
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION
 */
PHP_MINFO_FUNCTION(php_ext_example)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "php_ext_example support", "enabled");
	php_info_print_table_end();

	/* Remove comments if you have entries in php.ini
	DISPLAY_INI_ENTRIES();
	*/
}
/* }}} */

/* {{{ php_ext_example_functions[]
 *
 * Every user visible function must have an entry in php_ext_example_functions[].
 */
const zend_function_entry php_ext_example_functions[] = {
	PHP_FE(confirm_php_ext_example_compiled,	NULL)		/* For testing, remove later. */
	PHP_ME(SampleClass, sayHello, NULL, ZEND_ACC_PUBLIC)
	PHP_FE(self_concat, NULL)
	PHP_FE_END	/* Must be the last line in php_ext_example_functions[] */
};
/* }}} */

/* {{{ php_ext_example_module_entry
 */
zend_module_entry php_ext_example_module_entry = {
	STANDARD_MODULE_HEADER,
	"php_ext_example",
	php_ext_example_functions,
	PHP_MINIT(php_ext_example),
	PHP_MSHUTDOWN(php_ext_example),
	PHP_RINIT(php_ext_example),		/* Replace with NULL if there's nothing to do at request start */
	PHP_RSHUTDOWN(php_ext_example),	/* Replace with NULL if there's nothing to do at request end */
	PHP_MINFO(php_ext_example),
	PHP_PHP_EXT_EXAMPLE_VERSION,
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

#ifdef COMPILE_DL_PHP_EXT_EXAMPLE
ZEND_GET_MODULE(php_ext_example)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
