include openwrt.mk
include package.mk
SCRIPTS_DIR:=scripts
TOPDIR:=$(CURDIR)
PACKAGEDIR:=package
GIT := git
MAKE := make

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
	$(foreach package_makefile,$(wildcard $(PACKAGEDIR)/*),$(MAKE) -C $(CURDIR)/$(package_makefile))
