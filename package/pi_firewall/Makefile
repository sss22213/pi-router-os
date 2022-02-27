include $(TOPDIR)/$(INCLUDEDIR)/package.mk

# Package name
PKG_NAME:=pi_firewall

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/$(PKG_NAME)/beforebuild
	cp -v $(TOPDIR)/$(PACKAGEDIR)/$(PKG_NAME)/files/firewall.config $(TOPDIR)/$(OPENWRTDOR)/package/network/config/firewall/files
endef

define pi_router/$(PKG_NAME)/build
	
endef

define pi_router/$(PKG_NAME)/afterbuild
	
endef

$(eval $(call pi_router/package/build, $(PKG_NAME)))