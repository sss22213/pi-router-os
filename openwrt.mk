curdir := $(CURDIR)

define pi_router/pull/openwrt
	$(GIT) submodule init
	$(GIT) submodule update
endef
