dnl $Id$
dnl config.m4 for extension php_ext_example

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

PHP_ARG_WITH(php_ext_example, for php_ext_example support,
Make sure that the comment is aligned:
[  --with-php_ext_example             Include php_ext_example support])

dnl Otherwise use enable:

dnl PHP_ARG_ENABLE(php_ext_example, whether to enable php_ext_example support,
dnl Make sure that the comment is aligned:
dnl [  --enable-php_ext_example           Enable php_ext_example support])

if test "$PHP_PHP_EXT_EXAMPLE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-php_ext_example -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/php_ext_example.h"  # you most likely want to change this
  dnl if test -r $PHP_PHP_EXT_EXAMPLE/$SEARCH_FOR; then # path given as parameter
  dnl   PHP_EXT_EXAMPLE_DIR=$PHP_PHP_EXT_EXAMPLE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for php_ext_example files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       PHP_EXT_EXAMPLE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$PHP_EXT_EXAMPLE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the php_ext_example distribution])
  dnl fi

  dnl # --with-php_ext_example -> add include path
  dnl PHP_ADD_INCLUDE($PHP_EXT_EXAMPLE_DIR/include)

  dnl # --with-php_ext_example -> check for lib and symbol presence
  dnl LIBNAME=php_ext_example # you may want to change this
  dnl LIBSYMBOL=php_ext_example # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $PHP_EXT_EXAMPLE_DIR/$PHP_LIBDIR, PHP_EXT_EXAMPLE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_PHP_EXT_EXAMPLELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong php_ext_example lib version or lib not found])
  dnl ],[
  dnl   -L$PHP_EXT_EXAMPLE_DIR/$PHP_LIBDIR -lm
  dnl ])
  dnl
  dnl PHP_SUBST(PHP_EXT_EXAMPLE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(php_ext_example, php_ext_example.c, $ext_shared)
fi
