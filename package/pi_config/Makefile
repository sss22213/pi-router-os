include $(TOPDIR)/$(INCLUDEDIR)/package.mk

# Package name
PKG_NAME:=pi_config

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/$(PKG_NAME)/beforebuild
	@echo 1
endef


#$(MAKE) -C $(TOPDIR)/$(OPENWRTDOR) defconfig;
#$(MAKE) -C $(TOPDIR)/$(OPENWRTDOR) oldconfig;
#cd $(TOPDIR)/$(OPENWRTDOR);./scripts/diffconfig.sh > configdiff;
#cp $(TOPDIR)/$(OPENWRTDOR)/configdiff $(TOPDIR)/$(OPENWRTDOR)/.config;

define pi_router/$(PKG_NAME)/build
	cp -v $(TOPDIR)/$(PACKAGEDIR)/$(PKG_NAME)/files/config $(TOPDIR)/$(OPENWRTDOR)/.config
endef

define pi_router/$(PKG_NAME)/testbuild

endef

define pi_router/$(PKG_NAME)/afterbuild
	
endef


$(eval $(call pi_router/package/build, $(PKG_NAME)))