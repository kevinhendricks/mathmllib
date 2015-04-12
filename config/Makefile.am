
NULL =

MAINTERNERCLEANFILES = \
  gtkmathview.conf.xml \
  $(NULL)

EXTRA_DIST = \
  mathml-entities.dtd \
  dictionary.in \
  dictionary.dtd \
  dictionary.xml \
  dictionary-local.xml \
  dictionary-combining.xml \
  entities-table.in \
  entities-table.dtd \
  entities-table.xml \
  gtkmathview.conf.xml.in \
  gtkmathview.conf.dtd \
  gtkmathview.conf.xml \
  gtkmathview.conf.xml.debug \
  Makefile.slow \
  $(NULL)

pkgsysconfdir = $(sysconfdir)/@PACKAGE@
pkgsysconf_DATA = \
  gtkmathview.conf.xml

pkgdata_DATA = \
  mathml-entities.dtd \
  dictionary.dtd \
  dictionary.xml \
  dictionary-local.xml \
  dictionary-combining.xml \
  entities-table.dtd \
  entities-table.xml \
  gtkmathview.conf.dtd \
  $(NULL)

noinst_DATA = \
  gtkmathview.conf.xml.debug

install-data-hook:
	true
