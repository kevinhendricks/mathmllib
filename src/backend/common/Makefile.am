
NULL =

if COND_TFM
MAYBE_TFM_SUBDIRS = tfm
MAYBE_TFM_L = $(top_builddir)/src/backend/common/tfm/libtfm.la
else
MAYBE_TFM_SUBDIRS =
MAYBE_TFM_L = $(NULL)
endif

SUBDIRS = $(MAYBE_TFM_SUBDIRS)

noinst_LTLIBRARIES = libbackend_common.la

if COND_TFM
MAYBE_TFM_S = \
  TFMComputerModernShaper.cc \
  TFMComputerModernMathGraphicDevice.cc \
  TFMFont.cc \
  TFMFontManager.cc \
  TFMGlyphArea.cc \
  $(NULL)
MAYBE_TFM_H = \
  TFMComputerModernShaper.hh \
  TFMComputerModernMathGraphicDevice.hh \
  TFMFont.hh \
  TFMFontManager.hh \
  TFMGlyphArea.hh \
  $(NULL)
else
MAYBE_TFM_S = $(NULL)
MAYBE_TFM_H = $(NULL)
endif

libbackend_common_la_CPPFLAGS = -DGMV_MathView_DLL
libbackend_common_la_SOURCES = \
  Area.cc \
  AreaFactory.cc \
  AreaId.cc \
  AreaIdAux.cc \
  Backend.cc \
  BinContainerArea.cc \
  BoxArea.cc \
  BoxedLayoutArea.cc \
  ColorArea.cc \
  CombinedGlyphArea.cc \
  ComputerModernFamily.cc \
  ComputerModernShaper.cc \
  FormattingContext.cc \
  GlyphArea.cc \
  GlyphStringArea.cc \
  GlyphWrapperArea.cc \
  GraphicDevice.cc \
  HideArea.cc \
  HorizontalArrayArea.cc \
  HorizontalFillerArea.cc \
  HorizontalSpaceArea.cc \
  IdArea.cc \
  IgnoreArea.cc	\
  InkArea.cc \
  LinearContainerArea.cc \
  MathGraphicDevice.cc \
  NullShaper.cc \
  OverlapArrayArea.cc \
  Shaper.cc \
  ShaperManager.cc \
  ShapingContext.cc \
  ShiftArea.cc \
  SimpleArea.cc \
  SpaceShaper.cc \
  StandardSymbolsShaper.cc \
  StepArea.cc \
  VerticalArrayArea.cc \
  VerticalFillerArea.cc \
  VerticalSpaceArea.cc \
  WrapperArea.cc \
  $(MAYBE_TFM_S) \
  $(MAYBE_TFM_H) \
  $(NULL)

mathviewdir = $(pkgincludedir)/MathView
mathview_HEADERS = \
  Area.hh \
  AreaFactory.hh \
  AreaId.hh \
  AreaIdAux.hh \
  Backend.hh \
  BinContainerArea.hh \
  BoxArea.hh \
  BoxedLayoutArea.hh \
  CachedShapedString.hh \
  ColorArea.hh	\
  CombinedGlyphArea.hh \
  ComputerModernFamily.hh \
  ComputerModernShaper.hh \
  ContainerArea.hh \
  FillerArea.hh \
  FormattingContext.hh \
  GlyphArea.hh \
  GlyphSpec.hh \
  GlyphStringArea.hh \
  GlyphWrapperArea.hh \
  GraphicDevice.hh \
  HideArea.hh \
  HorizontalArrayArea.hh \
  HorizontalFillerArea.hh \
  HorizontalSpaceArea.hh \
  IdArea.hh \
  IgnoreArea.hh	\
  InkArea.hh \
  LinearContainerArea.hh \
  MathGraphicDevice.hh \
  NullShaper.hh \
  OverlapArrayArea.hh \
  RenderingContext.hh \
  SearchingContext.hh \
  Shaper.hh \
  ShaperManager.hh \
  ShapingContext.hh \
  ShiftArea.hh \
  SimpleArea.hh \
  SpaceShaper.hh \
  StandardSymbolsShaper.hh \
  StepArea.hh \
  T1Font.hh \
  VerticalArrayArea.hh \
  VerticalFillerArea.hh \
  VerticalSpaceArea.hh \
  WrapperArea.hh \
  $(MAYBE_TFM_H) \
  $(NULL)

CPPFLAGS = \
  -I$(top_srcdir)/auto \
  -I$(top_srcdir)/src/common \
  -I$(top_srcdir)/src/common/mathvariants \
  -I$(top_srcdir)/src/backend/common/tfm \
  -I$(top_srcdir)/src/engine/common \
  -I$(top_srcdir)/src/engine/mathml \
  $(NULL)

libbackend_common_la_LIBADD = \
  $(MAYBE_TFM_L) \
  $(NULL)

