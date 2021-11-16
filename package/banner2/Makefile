include ../../package.mk

# Package name
PKG_NAME:=banner2

# Package verison
PKG_VERSION:=1.0

# Minimunm support for openwrt
PKG_MINIMUM_VERSION := 21

define pi_router/banner2/beforebuild
	@echo 1
endef

define pi_router/banner2/build
	@echo 2
endef

define pi_router/banner2/afterbuild
	@echo 3
endef

$(eval $(call pi_router/package/build, $(PKG_NAME)))



