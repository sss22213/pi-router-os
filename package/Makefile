CURDIR := $(TOPDIR)/package
FIND := find
FINDPACKAGEDIR := $(shell $(FIND) $(CURDIR) -mindepth 1 -maxdepth 1 -type d -and \! -name "package")

pi_router/package/build:
	$(foreach pkg,$(FINDPACKAGEDIR),@echo $(pkg);$(MAKE) -f $(pkg)/Makefile;)

pi_router/package/clean:
	@echo clean

pi_router/package/install:
	@echo install

.PHONY: pi_router/package/build pi_router/package/clean pi_router/package/install
