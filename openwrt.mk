curdir := $(CURDIR)

define pi_router/pull/openwrt
	$(GIT) submodule init
	$(GIT) submodule update
endef

define pi_router/patch/openwrt

endef