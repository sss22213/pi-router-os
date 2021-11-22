include $(TOPDIR)/$(INCLUDEDIR)/package.mk

# Package name
PKG_NAME:=pi_config

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/$(PKG_NAME)/beforebuild
	cp -v $(TOPDIR)/$(PACKAGEDIR)/$(PKG_NAME)/files/config $(TOPDIR)/$(OPENWRTDOR)/.config
endef

define pi_router/$(PKG_NAME)/build
	cd $(OPENWRTDOR);./scripts/diffconfig.sh;cp configdiff .config;make defconfig;make oldconfig;
endef

define pi_router/$(PKG_NAME)/afterbuild
	
endef

$(PKG_NAME):
	$(call pi_router/package/build, $(PKG_NAME))