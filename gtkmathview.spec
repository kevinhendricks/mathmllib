Summary: A GTK Widget for rendering MathML documents
Name: gtkmathview
Version: 0.8.0
Release: 1
Copyright: GPL
Group: Development/Libraries
Source: www.cs.unibo.it:/helm/mml-widget/gtkmathview-0.8.0.tar.gz
%description
GtkMathView is a GTK Widget for rendering MathML documents.

%prep
%setup

%build
./configure
make

%install
make install

%files
%doc AUTHORS BUGS COPYING ChangeLog HISTORY INSTALL LICENSE NEWS README TODO 

/usr/local/bin/gtkmathview-config
/usr/local/bin/mathmlviewer
/usr/local/bin/mathml2ps
/usr/local/lib/libgtkmathview.so
/usr/local/lib/libgtkmathview.so.0
/usr/local/lib/libgtkmathview.so.0.8.0
/usr/local/lib/libgtkmathview.a
/usr/local/lib/libgtkmathview.la
/usr/local/include/gtkmathview/
/usr/local/share/gtkmathview/
/usr/local/info/gtkmathview.info
/usr/local/man/mathmlviewer.1
/usr/local/man/mathml2ps.1

