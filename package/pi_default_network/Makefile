include $(TOPDIR)/$(INCLUDEDIR)/package.mk

# Package name
PKG_NAME:=pi_default_network

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/$(PKG_NAME)/beforebuild
	cp -v $(TOPDIR)/$(PACKAGEDIR)/$(PKG_NAME)/files/mac80211.sh $(TOPDIR)/$(OPENWRTDOR)/package/kernel/mac80211/files/lib/wifi
endef

define pi_router/$(PKG_NAME)/build
	
endef

define pi_router/$(PKG_NAME)/afterbuild
	
endef

$(PKG_NAME):
	$(call pi_router/package/build, $(PKG_NAME))