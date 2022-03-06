include $(TOPDIR)/$(INCLUDEDIR)/package.mk

# Package name
PKG_NAME:=pi_web_ui

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/$(PKG_NAME)/beforebuild
	@echo 1
endef

define pi_router/$(PKG_NAME)/build
	cp -rv $(TOPDIR)/$(PACKAGEDIR)/$(PKG_NAME)/files/pi-router-os-web-ui $(TOPDIR)/$(OPENWRTDOR)/$(PACKAGEDIR)/base-files/files/usr
endef

define pi_router/$(PKG_NAME)/afterbuild
	
endef


$(eval $(call pi_router/package/build, $(PKG_NAME)))