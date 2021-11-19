SCRIPTS_DIR:=scripts
TOPDIR:=$(CURDIR)
INCLUDEDIR:=include
PACKAGEDIR:=package
OPENWRTDOR:=openwrt
GIT := git
MAKE := make

include include/openwrt.mk
include include/package.mk

all: pi_router/beforebuild pi_router/build

pi_router/beforebuild:
ifeq (${OS},Windows_NT)
	@echo Host can not support windows.
else
	sudo chmod +x $(SCRIPTS_DIR)/install_env.sh
	sudo ./$(SCRIPTS_DIR)/install_env.sh
endif
	$(call pi_router/pull/openwrt)

pi_router/build:
# Find all of package
	$(MAKE) -C $(PACKAGEDIR) pi_router/package/build \
				TOPDIR=$(TOPDIR) \
				INCLUDEDIR=$(INCLUDEDIR) \
				PACKAGEDIR=$(PACKAGEDIR) \
				OPENWRTDOR=$(OPENWRTDOR)
# Build openwrt
#$(MAKE) -C $(OPENWRTDOR) -j6 V=s

.PHONY: all pi_router/beforebuild pi_router/build
