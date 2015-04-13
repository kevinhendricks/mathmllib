dnl Process this file with autoconf to produce a configure script.

dnl Automake configuration
AC_INIT([gtkmathview], [0.8.0])
AC_CONFIG_SRCDIR([src/common/Clock.hh])
AC_CONFIG_MACRO_DIR([m4])
AM_CONFIG_HEADER([config.h])
AM_INIT_AUTOMAKE([subdir-objects foreign])
AM_SILENT_RULES([yes])
AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL

MATHVIEW_MAJOR_VERSION=0
MATHVIEW_MINOR_VERSION=8
MATHVIEW_MICRO_VERSION=0
MATHVIEW_VERSION=$MATHVIEW_MAJOR_VERSION.$MATHVIEW_MINOR_VERSION.$MATHVIEW_MICRO_VERSION
MATHVIEW_VERSION_INFO=`expr $MATHVIEW_MAJOR_VERSION + $MATHVIEW_MINOR_VERSION`:$MATHVIEW_MICRO_VERSION:$MATHVIEW_MINOR_VERSION

MAJOR_VERSION=$MATHVIEW_MAJOR_VERSION
MINOR_VERSION=$MATHVIEW_MINOR_VERSION
VERSION=$MATHVIEW_VERSION

AC_SUBST(MAJOR_VERSION)
AC_SUBST(MINOR_VERSION)
AC_SUBST(MATHVIEW_VERSION)
AC_SUBST(MATHVIEW_VERSION_INFO)

AREAMODEL_VERSION_INFO=$MATHVIEW_VERSION_INFO
AC_SUBST(AREAMODEL_VERSION_INFO)

enable_builder_cache="no"
enable_pipe="no"
enable_profile="no"
enable_breaks="no"
enable_gmetadom="no"
enable_gtk="no"
enable_ps="no"
enable_gcc_pch="auto"
with_t1lib="no"
with_t1lib_prefix="no"

AC_ARG_ENABLE(debug,
	[--enable-debug[=ARG]    include debugging debug [default=yes]],
	[enable_debug=$enableval],
	[enable_debug="no"]
)

AC_ARG_ENABLE(libxml2,
	[  --enable-libxml2[=ARG]   enable the libxml2 frontend [default=auto]],
	[enable_libxml2=$enableval],
	[enable_libxml2="auto"]
)

AC_ARG_ENABLE(libxml2-reader,
	[  --enable-libxml2-reader[=ARG] enable the libxml2 reader frontend [default=auto]],
	[enable_libxml2_reader=$enableval],
	[enable_libxml2_reader="auto"]
)

AC_ARG_ENABLE(custom-reader,
	[  --enable-custom-reader[=ARG] enable the custom reader frontend [default=yes]],
	[enable_custom_reader=$enableval],
	[enable_custom_reader="yes"]
)

AC_ARG_ENABLE(tfm,
	[  --enable-tfm[=ARG]  enable support level for TeX Font Metrics (0,1,2,3) [disabled=0,default=2]],
	[enable_tfm=$enableval],
	[enable_tfm="2"]
)
if test $enable_tfm = "yes"; then
  enable_tfm="2"
elif test $enable_tfm = "no"; then
  enable_tfm="0"
fi

AC_ARG_ENABLE(svg,
	[  --enable-svg[=ARG]  enable SVG backend [default=yes]],
	[enable_svg=$enableval],
	[enable_svg="yes"]
)

AC_ARG_WITH(popt-prefix,
        [  --with-popt-prefix=PFX prefix dir where popt is installed],
        [
                with_popt_prefix="yes"
                POPT_PREFIX=$withval
        ],
        [
                with_popt_prefix="no"
        ]
)

AC_ARG_WITH(popt,
	[  --with-popt[=ARG] use popt - required for mathmlsvg (default=auto)],
	[with_popt=$withval],
	[with_popt="auto"]
)

if test "x$enable_breaks" = "xyes"; then
   AC_DEFINE(ENABLE_BREAKS,1,[Define to 1 if you want to enable linebreaking using mspace elements])
fi

dnl Checks for programs.
AC_PROG_CC
AC_PROG_CXX
PKG_PROG_PKG_CONFIG([0.20])
AM_MISSING_PROG([PYTHON], [python2.7])
AC_PROG_LN_S
AC_ISC_POSIX

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_BIGENDIAN
AC_C_CHAR_UNSIGNED
AC_CHECK_SIZEOF(unsigned char, 1)
AC_CHECK_SIZEOF(unsigned short, 2)
AC_CHECK_SIZEOF(unsigned int, 4)
AC_CHECK_SIZEOF(unsigned long, 4)
AC_CHECK_SIZEOF(unsigned long long, 8)
AC_CHECK_SIZEOF(wchar_t, 8)
if test "x$ac_cv_c_char_unsigned" = "xyes"; then
   AC_SUBST(CHAR_UNSIGNED, "1")
else
   AC_SUBST(CHAR_UNSIGNED, "0")
fi
AC_SUBST(GTKMATHVIEW_SIZEOF_CHAR, "$ac_cv_sizeof_unsigned_char")
AC_SUBST(GTKMATHVIEW_SIZEOF_SHORT, "$ac_cv_sizeof_unsigned_short")
AC_SUBST(GTKMATHVIEW_SIZEOF_INT, "$ac_cv_sizeof_unsigned_int")
AC_SUBST(GTKMATHVIEW_SIZEOF_LONG, "$ac_cv_sizeof_unsigned_long")
AC_SUBST(GTKMATHVIEW_SIZEOF_LONG_LONG, "$ac_cv_sizeof_unsigned_long_long")
AC_SUBST(GTKMATHVIEW_SIZEOF_WCHAR_T, "$ac_cv_sizeof_wchar_t")


AC_LANG_PUSH(C++)
 
AC_CHECK_HEADERS(unordered_map,
    [
        AC_DEFINE(GMV_HAVE_UNORDERED_MAP,1,[Define if <unordered_map> is provided])
        GMV_HAVE_UNORDERED_MAP_CFLAGS=-DGMV_HAVE_UNORDERED_MAP=1
    ],
    [
        GMV_HAVE_UNORDERED_MAP_CFLAGS=
    ]
)
AC_SUBST(GMV_HAVE_UNORDERED_MAP_CFLAGS)

AC_CHECK_HEADERS(hash_map,
	[
		AC_DEFINE(GMV_HAVE_HASH_MAP,1,[Define if <hash_map> is provided])
		GMV_HAVE_HASH_MAP_CFLAGS=-DGMV_HAVE_HASH_MAP=1
	],
	[
		GMV_HAVE_HASH_MAP_CFLAGS=
	]
)
AC_SUBST(GMV_HAVE_HASH_MAP_CFLAGS)
AC_CHECK_HEADERS(ext/hash_map,
	[
		AC_DEFINE(GMV_HAVE_EXT_HASH_MAP,1,[Define if <ext/hash_map> is provided])
		GMV_HAVE_EXT_HASH_MAP_CFLAGS=-DGMV_HAVE_EXT_HASH_MAP=1
	],
	[
		GMV_HAVE_EXT_HASH_MAP_CFLAGS=
	]
)
AC_SUBST(GMV_HAVE_EXT_HASH_MAP_CFLAGS)

AC_MSG_CHECKING([whether the C++ compiler supports the standard character traits])
AC_TRY_LINK(
	[#include <string>],
	[
		std::basic_string<char> s1;
		std::basic_string<wchar_t> s2;
		std::basic_string<wchar_t> s3;
		s2 = s3;
	],
	[
		AC_DEFINE(STD_TRAITS,1,[Define to 1 if standard traits for char and wchar_t are provided])
		AC_MSG_RESULT(yes)
	],
	[
		AC_MSG_RESULT(no)
	]
)

AC_LANG_POP(C++)

AC_CHECK_PROG(HAVE_XSLTPROC, xsltproc, yes, no)
if test $HAVE_XSLTPROC = "no"; then
	AC_MSG_WARN(xsltproc not found, the compilation may fail)
fi
AM_CONDITIONAL([COND_XSLTPROC], [test "$HAVE_XSLTPROC" = "yes"])

have_popt="no"
if test $with_popt = "auto"; then
	AC_CHECK_HEADERS(popt.h,[
		AC_CHECK_LIB(popt, poptGetContext, [have_popt="yes"])
	])
else
	have_popt=$with_popt
fi

if test $have_popt = "yes"; then
	AC_DEFINE(HAVE_POPT_H,1,[Define to 1 if popt.h is available])

        if test $with_popt_prefix = "yes"; then
                POPT_CFLAGS="-I$POPT_PREFIX/include"
		POPT_LIBS="-L$POPT_PREFIX/lib -lpopt"
	else
		POPT_CFLAGS=$CFLAGS
		POPT_LIBS="$LDFLAGS -lpopt"
        fi
else
	POPT_CFLAGS=""
	POPT_LIBS=""
fi
AM_CONDITIONAL([COND_HAVE_POPT], [test "$have_popt" = "yes"])
AC_SUBST(POPT_CFLAGS)
AC_SUBST(POPT_LIBS)

have_gtk="no"
have_pango="no"

AM_CONDITIONAL([COND_GTK], [test "$enable_gtk" = "yes" -o \( "$enable_gtk" = "auto" -a \( "$have_gtk" = "yes" -a "$have_pango" = "yes" \) \) ])

AM_CONDITIONAL([COND_CUSTOM_READER], [test "$enable_custom_reader" = "yes" -o "$enable_custom_reader" = "auto"])

have_libxml2="no"
PKG_CHECK_MODULES([XML], [libxml-2.0 >= 2.6.7], [have_libxml2="yes"], :)
if test "x$have_libxml2" = "xyes"; then
  AC_DEFINE(HAVE_LIBXML,1,[Define to 1 if libxml2 is installed])
else
  AC_MSG_ERROR(could not find libxml2)
fi
AC_SUBST(XML_CFLAGS)
AC_SUBST(XML_LIBS)
AM_CONDITIONAL([COND_LIBXML2], [test "$enable_libxml2" = "yes" -o \( "$enable_libxml2" = "auto" -a "$have_libxml2" = "yes" \)]) 
AM_CONDITIONAL([COND_LIBXML2_READER], [test "$enable_libxml2_reader" = "yes" -o \( "$enable_libxml2_reader" = "auto" -a "$have_libxml2" = "yes" \)]) 

have_gmetadom="no"
have_t1lib="no"

CFLAGS="$CFLAGS -W -Wall"
CXXFLAGS="$CXXFLAGS -W -Wall"

if test $enable_debug = yes; then
	CFLAGS="$CFLAGS -O0"
	CXXFLAGS="$CXXFLAGS -O0"
	AC_DEFINE(ENABLE_DEBUG,1,[Define to 1 if you want to enable validity checks while running])
fi

AM_CONDITIONAL([COND_PROFILE], [test "$enable_profile" = "yes"])

if test $enable_builder_cache = yes; then
    AC_DEFINE(ENABLE_BUILDER_CACHE,1,[Define to 1 to enable caching of MathML Text nodes (slower but saves memory)])	
fi

AC_DEFINE_UNQUOTED(GMV_TFM_LEVEL, $enable_tfm, [Define to 0, 1, 2, or 3 depending on the TFM support level you want])
AM_CONDITIONAL([COND_TFM], [test "$enable_tfm" != "0"])
AM_CONDITIONAL([COND_TFM_LEVEL_1], [test "$enable_tfm" = "1"])
AM_CONDITIONAL([COND_TFM_LEVEL_2], [test "$enable_tfm" = "2"])
AM_CONDITIONAL([COND_TFM_LEVEL_3], [test "$enable_tfm" = "3"])

if test "$enable_tfm" = "0" -a "$enable_svg" = "yes"; then
	AC_MSG_WARN([SVG support requires TFM support])
	enable_svg="no"
fi
	
if test "$enable_svg" = "yes"; then
	AC_DEFINE(ENABLE_SVG,1,[Define to 1 if you want to enable the SVG backend])
fi
AM_CONDITIONAL([COND_SVG], [test "$enable_svg" = "yes"])

if test "$enable_ps" = "yes"; then
	AC_DEFINE(ENABLE_PS,1,[Define to 1 if you want to enable the PostScript backend])
fi
AM_CONDITIONAL([COND_PS], [test "$enable_ps" = "yes"])

AM_CONDITIONAL(WITH_BINRELOC, test "x$br_cv_binreloc" = "xyes")

AC_MSG_CHECKING([whether to use GCC precompiled headers with $CXX])
if test "x$GCC" = "xyes" ; then
	_gmv_gcc_version=`$CXX --version | grep GCC | head -1 | cut -f 3 -d " "`
        _gmv_gcc_major=`echo $_gmv_gcc_version | cut -f 1 -d "."`

	if [[ $_gmv_gcc_major -ge 4 ]] ; then
		if test "x$enable_gcc_pch" = "xyes" ; then
			AC_MSG_RESULT(yes)
			gmv_gcc_pch="yes"
		elif test "x$enable_gcc_pch" = "xauto" ; then
			AC_MSG_RESULT(yes)
			gmv_gcc_pch="yes"
		else
			AC_MSG_RESULT(no)
			gmv_gcc_pch="no"
		fi
	else
		AC_MSG_RESULT(no)
		gmv_gcc_pch="no"
	fi
else
	gmv_gcc_pch="no"
fi
AM_CONDITIONAL(USE_GCC_PCH, test "x$gmv_gcc_pch" = "xyes")

AC_CONFIG_FILES([
 Makefile
 config/Makefile
 config/gtkmathview.conf.xml
 scripts/Makefile
 auto/Makefile
 auto/Char.hh.in
 src/Makefile
 src/common/Makefile
 src/common/mathvariants/Makefile
 src/common/mathvariants/xml/Makefile
 src/frontend/Makefile
 src/frontend/common/Makefile
 src/frontend/custom_reader/Makefile
 src/frontend/libxml2_reader/Makefile
 src/frontend/libxml2/Makefile
 src/engine/Makefile
 src/engine/common/Makefile
 src/engine/mathml/Makefile
 src/backend/Makefile
 src/backend/common/Makefile
 src/backend/common/tfm/Makefile
 src/backend/svg/Makefile
 src/view/Makefile
 mathmlsvg/Makefile
 doc/Makefile
 mathview-core.pc
 mathview-frontend-custom-reader.pc
 mathview-frontend-libxml2-reader.pc
 mathview-frontend-libxml2.pc
 mathview-backend-svg.pc
])
AC_OUTPUT

cat <<EOF

GtkMathView ${MATHVIEW_VERSION}

Compilation

  Debugging           ${enable_debug}
  xsltproc            ${HAVE_XSLTPROC}
  popt                ${have_popt}

Engine

  MathML              yes

Frontend

  libxml2             ${enable_libxml2}
  libxml2 reader      ${enable_libxml2_reader}
  custom reader       ${enable_custom_reader}

Backend

  TFM support level   ${enable_tfm}
  SVG                 ${enable_svg}

Performance

  Builder cache       ${enable_builder_cache}

EOF
