#############################################################################
# Makefile for building: qexp
# Generated by qmake (2.01a) (Qt 4.8.1) on: Thu Jan 19 19:53:33 2017
# Project:  qexp.pro
# Template: app
# Command: /usr/bin/qmake -o Makefile qexp.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_WEBKIT -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I/usr/share/qt4/mkspecs/linux-g++-64 -I. -I/usr/include/qt4/QtCore -I/usr/include/qt4/QtGui -I/usr/include/qt4 -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib/x86_64-linux-gnu -lQtGui -lQtCore -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = addwindow.cpp \
		book.cpp \
		main.cpp \
		mainwindow.cpp \
		mymodel.cpp \
		totwindow.cpp moc_addwindow.cpp \
		moc_mainwindow.cpp \
		moc_mymodel.cpp \
		moc_totwindow.cpp
OBJECTS       = addwindow.o \
		book.o \
		main.o \
		mainwindow.o \
		mymodel.o \
		totwindow.o \
		moc_addwindow.o \
		moc_mainwindow.o \
		moc_mymodel.o \
		moc_totwindow.o
DIST          = /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		qexp.pro
QMAKE_TARGET  = qexp
DESTDIR       = 
TARGET        = qexp

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: qexp.pro  /usr/share/qt4/mkspecs/linux-g++-64/qmake.conf /usr/share/qt4/mkspecs/common/unix.conf \
		/usr/share/qt4/mkspecs/common/linux.conf \
		/usr/share/qt4/mkspecs/common/gcc-base.conf \
		/usr/share/qt4/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt4/mkspecs/common/g++-base.conf \
		/usr/share/qt4/mkspecs/common/g++-unix.conf \
		/usr/share/qt4/mkspecs/qconfig.pri \
		/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri \
		/usr/share/qt4/mkspecs/features/qt_functions.prf \
		/usr/share/qt4/mkspecs/features/qt_config.prf \
		/usr/share/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt4/mkspecs/features/default_pre.prf \
		/usr/share/qt4/mkspecs/features/release.prf \
		/usr/share/qt4/mkspecs/features/default_post.prf \
		/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt4/mkspecs/features/warn_on.prf \
		/usr/share/qt4/mkspecs/features/qt.prf \
		/usr/share/qt4/mkspecs/features/unix/thread.prf \
		/usr/share/qt4/mkspecs/features/moc.prf \
		/usr/share/qt4/mkspecs/features/resources.prf \
		/usr/share/qt4/mkspecs/features/uic.prf \
		/usr/share/qt4/mkspecs/features/yacc.prf \
		/usr/share/qt4/mkspecs/features/lex.prf \
		/usr/share/qt4/mkspecs/features/include_source_dir.prf \
		/usr/lib/x86_64-linux-gnu/libQtGui.prl \
		/usr/lib/x86_64-linux-gnu/libQtCore.prl
	$(QMAKE) -o Makefile qexp.pro
/usr/share/qt4/mkspecs/common/unix.conf:
/usr/share/qt4/mkspecs/common/linux.conf:
/usr/share/qt4/mkspecs/common/gcc-base.conf:
/usr/share/qt4/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt4/mkspecs/common/g++-base.conf:
/usr/share/qt4/mkspecs/common/g++-unix.conf:
/usr/share/qt4/mkspecs/qconfig.pri:
/usr/share/qt4/mkspecs/modules/qt_webkit_version.pri:
/usr/share/qt4/mkspecs/features/qt_functions.prf:
/usr/share/qt4/mkspecs/features/qt_config.prf:
/usr/share/qt4/mkspecs/features/exclusive_builds.prf:
/usr/share/qt4/mkspecs/features/default_pre.prf:
/usr/share/qt4/mkspecs/features/release.prf:
/usr/share/qt4/mkspecs/features/default_post.prf:
/usr/share/qt4/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt4/mkspecs/features/warn_on.prf:
/usr/share/qt4/mkspecs/features/qt.prf:
/usr/share/qt4/mkspecs/features/unix/thread.prf:
/usr/share/qt4/mkspecs/features/moc.prf:
/usr/share/qt4/mkspecs/features/resources.prf:
/usr/share/qt4/mkspecs/features/uic.prf:
/usr/share/qt4/mkspecs/features/yacc.prf:
/usr/share/qt4/mkspecs/features/lex.prf:
/usr/share/qt4/mkspecs/features/include_source_dir.prf:
/usr/lib/x86_64-linux-gnu/libQtGui.prl:
/usr/lib/x86_64-linux-gnu/libQtCore.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile qexp.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/qexp1.0.0 || $(MKDIR) .tmp/qexp1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/qexp1.0.0/ && $(COPY_FILE) --parents addwindow.h book.h coreds.h mainwindow.h mymodel.h totwindow.h .tmp/qexp1.0.0/ && $(COPY_FILE) --parents addwindow.cpp book.cpp main.cpp mainwindow.cpp mymodel.cpp totwindow.cpp .tmp/qexp1.0.0/ && (cd `dirname .tmp/qexp1.0.0` && $(TAR) qexp1.0.0.tar qexp1.0.0 && $(COMPRESS) qexp1.0.0.tar) && $(MOVE) `dirname .tmp/qexp1.0.0`/qexp1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/qexp1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_addwindow.cpp moc_mainwindow.cpp moc_mymodel.cpp moc_totwindow.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_addwindow.cpp moc_mainwindow.cpp moc_mymodel.cpp moc_totwindow.cpp
moc_addwindow.cpp: mymodel.h \
		coreds.h \
		book.h \
		addwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) addwindow.h -o moc_addwindow.cpp

moc_mainwindow.cpp: mymodel.h \
		coreds.h \
		book.h \
		mainwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_mymodel.cpp: coreds.h \
		book.h \
		mymodel.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) mymodel.h -o moc_mymodel.cpp

moc_totwindow.cpp: mymodel.h \
		coreds.h \
		book.h \
		totwindow.h
	/usr/bin/moc-qt4 $(DEFINES) $(INCPATH) totwindow.h -o moc_totwindow.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all:
compiler_uic_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

addwindow.o: addwindow.cpp addwindow.h \
		mymodel.h \
		coreds.h \
		book.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o addwindow.o addwindow.cpp

book.o: book.cpp book.h \
		coreds.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o book.o book.cpp

main.o: main.cpp mainwindow.h \
		mymodel.h \
		coreds.h \
		book.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		mymodel.h \
		coreds.h \
		book.h \
		totwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

mymodel.o: mymodel.cpp mymodel.h \
		coreds.h \
		book.h \
		addwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mymodel.o mymodel.cpp

totwindow.o: totwindow.cpp totwindow.h \
		mymodel.h \
		coreds.h \
		book.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o totwindow.o totwindow.cpp

moc_addwindow.o: moc_addwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_addwindow.o moc_addwindow.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_mymodel.o: moc_mymodel.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mymodel.o moc_mymodel.cpp

moc_totwindow.o: moc_totwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_totwindow.o moc_totwindow.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:
