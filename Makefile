include openwrt.mk
include package.mk
SCRIPTS_DIR:=scripts
TOPDIR:=$(CURDIR)
PACKAGEDIR:=package
GIT := git
MAKE := make

all: preprocess
preprocess:
ifeq (${OS},Windows_NT)
	@echo Host can not support windows.
else
	sudo chmod +x $(SCRIPTS_DIR)/install_env.sh
	sudo ./$(SCRIPTS_DIR)/install_env.sh
endif
	$(call pi_router/pull/openwrt)
	${call pi_router/package/preprocess}
	 
