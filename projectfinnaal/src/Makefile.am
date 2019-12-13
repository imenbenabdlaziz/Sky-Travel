## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project31

project31_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonctions.c fonctions.h \
	employers.c employers.h \
	interfaceadmin.c interfaceadmin.h \
	fonctionh.c fontionh.h \
	interfacehe.c interfacehe.h \
	interfacere.c interfacere.h \
	gestionhotel.c gestionhotel.h \
	gest.c gest.h \
	interfacev.c interfacev.h \
	interfacen.c interfacen.h\
	reclamation.c reclamation.h
	
project31_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

