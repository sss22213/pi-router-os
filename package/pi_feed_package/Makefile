include $(TOPDIR)/$(INCLUDEDIR)/package.mk

# Package name
PKG_NAME:=pi_feed_package

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/$(PKG_NAME)/beforebuild
	cp -rv $(TOPDIR)/$(PACKAGEDIR)/$(PKG_NAME)/files/libpahomqtt $(TOPDIR)/$(OPENWRTDOR)/feeds/packages/libs
endef

define pi_router/$(PKG_NAME)/build
	
endef

define pi_router/$(PKG_NAME)/afterbuild
	
endef

$(eval $(call pi_router/package/build, $(PKG_NAME)))