/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */


/* Copyright (C) 2000-2007, Luca Padovani <padovani@sti.uniurb.it>.
 *
 * This file is part of GtkMathView, a flexible, high-quality rendering
 * engine for MathML documents.
 * 
 * GtkMathView is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 * 
 * GtkMathView is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef config_h
#define config_h


/* Define to 1 if you want to enable linebreaking using mspace elements */
/* #undef ENABLE_BREAKS */

/* Define to 1 to enable caching of MathML Text nodes (slower but saves
   memory) */
/* #undef ENABLE_BUILDER_CACHE */

/* Define to 1 if you want to enable validity checks while running */
/* #undef ENABLE_DEBUG */

/* Define to 1 to let the widget collect some information for profiling
   purposes */
/* #undef ENABLE_PROFILE */

/* Define to 1 if you want to enable the PostScript backend */
/* #undef ENABLE_PS */

/* Define to 1 if you want to enable the SVG backend */
#define ENABLE_SVG 1

/* Define to 1 if you want support for BoxML markup */
/* #undef GMV_ENABLE_BOXML */

/* Define if <ext/hash_map> is provided */
#define GMV_HAVE_EXT_HASH_MAP 1

/* Define if <hash_map> is provided */
/* #undef GMV_HAVE_HASH_MAP */

/* Define to 0, 1, 2, or 3 depending on the TFM support level you want */
#define GMV_TFM_LEVEL 2

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <ext/hash_map> header file. */
#define HAVE_EXT_HASH_MAP 1

/* Define to 1 if gmetadom is installed */
/* #undef HAVE_GMETADOM */

/* Define to 1 if GTK+ is installed */
/* #undef HAVE_GTK */

/* Define to 1 if you have the <hash_map> header file. */
/* #undef HAVE_HASH_MAP */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 to compile with t1lib for Type 1 fonts */
/* #undef HAVE_LIBT1 */

/* Define to 1 if libxml2 is installed */
#define HAVE_LIBXML 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if Pango is installed */
/* #undef HAVE_PANGO */

/* Define to 1 if popt.h is available */
#define HAVE_POPT_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <t1lib.h> header file. */
/* #undef HAVE_T1LIB_H */

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Name of package */
#define PACKAGE "gtkmathview"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* The size of `unsigned char', as computed by sizeof. */
#define SIZEOF_UNSIGNED_CHAR 1

/* The size of `unsigned int', as computed by sizeof. */
#define SIZEOF_UNSIGNED_INT 4

/* The size of `unsigned long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG 8

/* The size of `unsigned long long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* The size of `unsigned short', as computed by sizeof. */
#define SIZEOF_UNSIGNED_SHORT 2

/* The size of `wchar_t', as computed by sizeof. */
#define SIZEOF_WCHAR_T 4

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if standard traits for char and wchar_t are provided */
#define STD_TRAITS 1

/* Version number of package */
#define VERSION "0.8.0"

/* Define to 1 if your processor stores words with the most significant byte
   first (like Motorola and SPARC, unlike Intel and VAX). */
/* #undef WORDS_BIGENDIAN */

/* Define to 1 if type `char' is unsigned and you are not using gcc.  */
#ifndef __CHAR_UNSIGNED__
/* # undef __CHAR_UNSIGNED__ */
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */


#define GMV_ENABLE_TFM (GMV_TFM_LEVEL != 0)

#endif /* config_h */

