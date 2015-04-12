# mathmllib

Project: MathMLLib

This repository holds a highly modified copy of the (unmaintained?) LGPL 
project gtkmathview.  It is based on version 0.8.0 with lots of updates 
to fix the bitrot, and remove many unneeded pieces.

Removed pieces include all widget support, mathml2ps, and BoxML.

Much more modification is needed.  The goal is to create a new library that 
will interface to a Gumbo node tree (see gumbo-parser) and take any mathml 
in any xhtml/html5 page and replace it on the fly with inline svg code so 
that webkit widgets and other browser engines that do not support MathML 
(such a QWebKit, QWebEngine, Chrome, etc) can support full MathML for display
without the need to use the much slower MathJax implementation.

The build dependencies right now are:
  - popt for mathmlsvg command line parsing
  - libxml2 as a front end to mathmlsvg
  - pkg-config (>= version 0.20)

All of these dependencies will be removed eventually and replaced with a single 
library that interfaces to a Gumbo node tree after parsing html5

What is present now in this repo is buildable (as tested on Mac OS X 10.10.2).
A recent C++ compiler is needed, as is autmake, autoconf, libtool for the build.

Currently the build process is:

./autogen.sh
./configure --disable-libxml2-reader --disable-custom-reader  --enable-libxml2
make

The commandline version of mathmlsvg should build inside the mathmlsvg directory

The entire build process will eventually mutate into a cmake based one with heavy 
reorganization.

Please note, the svg backend makes heavy use of the font metrics from the freely 
available ComputerModern ttf fonts.  These can be downloaded from the original
gtkmathview website and many places online (ie. Linux repositories).  For best 
results These fonts should be installed into the system meant to display the svg.
