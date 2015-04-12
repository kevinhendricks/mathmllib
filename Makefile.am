
NULL =

if COND_SVG
if COND_HAVE_POPT
MAYBE_SVG_SUBDIRS = mathmlsvg
else
MAYBE_SVG_SUBDIRS = $(NULL)
endif
else
MAYBE_SVG_SUBDIRS = $(NULL)
endif

EXTRA_DIST = LICENSE CONTRIBUTORS config.h.in README.MacOSX
SUBDIRS = scripts config auto src doc $(MAYBE_SVG_SUBDIRS)
CLEANFILES = core *.log *.eps

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = mathview-core.pc
if COND_LIBXML2
pkgconfig_DATA += mathview-frontend-libxml2.pc
endif
if COND_LIBXML2_READER
pkgconfig_DATA += mathview-frontend-libxml2-reader.pc
endif
if COND_CUSTOM_READER
pkgconfig_DATA += mathview-frontend-custom-reader.pc
endif

if COND_SVG
pkgconfig_DATA += mathview-backend-svg.pc
endif

SCRIPTDIR = ./scripts

backup:
	tar cvfz ../@PACKAGE@-@VERSION@-`date|tr ' ' '_'|tr ':' '_'`.tar.gz .

cleanbak:
	-rm -f `find . -name "*~"`

lc:
	@( \
	CFILES=`find $(top_srcdir) -name "*.c"`; \
	HFILES=`find $(top_srcdir) -name "*.h"`; \
	CCFILES=`find $(top_srcdir) -name "*.cc"`; \
	HHFILES=`find $(top_srcdir) -name "*.hh"`; \
	ICCFILES=`find $(top_srcdir) -name "*.icc"`; \
	wc -l $$CFILES $$HFILES $$CCFILES $$HHFILES $$ICCFILES | tail -n 1 \
	)

distdiff:
	diff -r src/ @PACKAGE@-@VERSION@/src/ | grep '.\(cc\|hh\)$$'

