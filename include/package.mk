CURDIR := $(TOPDIR)/package

define pi_router/package/build
	$(call pi_router/$(strip $(1))/beforebuild)
	$(call pi_router/$(strip $(1))/build)
	$(call pi_router/$(strip $(1))/afterbuild)
endef