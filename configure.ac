AC_INIT([kitty], [0.1], [suprdewd@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
    Makefile
    src/Makefile
])

PKG_CHECK_MODULES([GTK3], [gtk+-3.0])
PKG_CHECK_MODULES([WEBKIT2GTK3], [webkit2gtk-3.0])

AC_OUTPUT
