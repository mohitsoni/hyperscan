# Makefile

SUBDIRS = src
PRJNAME = hyperscan

TARGETS = $(SUBDIRS) LICENSE Makefile README ChangeLog docs

all:
	@( for dir in $(SUBDIRS) ; do \
		( cd $$dir ; \
		[ -f Makefile ] && make all ; \
		cd .. ); \
	done )

clean:
	@( for dir in $(SUBDIRS) ; do \
		( cd $$dir ; \
		[ -f Makefile ] && make clean ; \
		cd ..); \
	done )

install:
	@( for dir in $(SUBDIRS) ; do \
		( cd $$dir ; \
		[ -f Makefile ] && make install ; \
		cd ..); \
	done )

uninstall:
	@( for dir in $(SUBDIRS) ; do \
		(cd $$dir ; \
		[ -f Makefile ] && make uninstall ; \
		cd ..); \
	done )

help:
	@echo "Building targets:"
	@echo "all (default) 	- builds all"
	@echo "clean		- removes generated files"
	@echo "install		- install all binaries"
	@echo "uninstall	- uninstall all binaries"
	@echo	
