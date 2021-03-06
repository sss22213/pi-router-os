CURDIR := $(TOPDIR)/package
PKG_ALL_MINIMUM_VERSION := 20
FIND := find
FINDPACKAGEDIR = $(shell $(FIND) $(CURDIR) -mindepth 1 -maxdepth 1 -type d -and \! -name "package")

define pi_router/package/build
.PHONY: $(1)
$(1):
ifeq ($(shell expr $(PKG_MINIMUM_VERSION) \>= $(PKG_ALL_MINIMUM_VERSION)),1)
	$(call pi_router/$(strip $(1))/beforebuild)
	$(call pi_router/$(strip $(1))/build)
	$(call pi_router/$(strip $(1))/afterbuild)
else
	@echo "Package" $(1) "version is" ${PKG_MINIMUM_VERSION}, "But minimunm require is" $(PKG_ALL_MINIMUM_VERSION).
endif

endef
