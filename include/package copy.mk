CURDIR := $(TOPDIR)/package
FIND := find
FINDPACKAGEDIR = $(shell $(FIND) $(CURDIR) -mindepth 1 -maxdepth 1 -type d -and \! -name "package")

define pi_router/package/build
	$(call pi_router/$(strip $(1))/beforebuild)
	$(call pi_router/$(strip $(1))/build)
	$(call pi_router/$(strip $(1))/afterbuild)
endef