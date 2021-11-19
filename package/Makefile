CURDIR := $(TOPDIR)/package
PACKAGE_LIST := $(filter-out %Makefile, $(wildcard $(CURDIR)/*))

pi_router/package/build:
	$(foreach package_makefile,$(PACKAGE_LIST),$(MAKE) -C $(package_makefile) \
												TOPDIR=$(TOPDIR) \
												INCLUDEDIR=$(INCLUDEDIR) \
												PACKAGEDIR=$(PACKAGEDIR) \
												OPENWRTDOR=$(OPENWRTDOR);)

pi_router/package/clean:
	@echo clean

pi_router/package/install:
	@echo install

.PHONY: pi_router/package/build pi_router/package/clean pi_router/package/install