SCRIPTS_DIR:=scripts
TOPDIR:=$(CURDIR)
INCLUDEDIR:=include
PACKAGEDIR:=package
OPENWRTDOR:=openwrt
BUILDFOLDER:=build
GIT := git
MAKE := make

include include/openwrt.mk
include include/package.mk

all: pi_router/beforebuild pi_router/build

pi_router/beforebuild:
ifeq (${OS},Windows_NT)
	@echo Host can not support windows.
else
# Pull lastest openwrt PR
	$(call pi_router/pull/openwrt)
# Install environment for building openwrt
	sudo chmod +x $(SCRIPTS_DIR)/install_env.sh
	sudo ./$(SCRIPTS_DIR)/install_env.sh
	$(MAKE) -C $(OPENWRTDOR) defconfig;
	$(MAKE) -C $(OPENWRTDOR) clean;
# Update openwrt package
	cd $(OPENWRTDOR);./scripts/feeds update -a;./scripts/feeds install -a;
endif

pi_router/build:
# Find all of package
	$(MAKE) -C $(PACKAGEDIR) pi_router/package/build \
				TOPDIR=$(TOPDIR) \
				INCLUDEDIR=$(INCLUDEDIR) \
				PACKAGEDIR=$(PACKAGEDIR) \
				OPENWRTDOR=$(OPENWRTDOR)

# Create build folder
	mkdir -p build

# Build openwrt
	$(MAKE) -C $(OPENWRTDOR) -j6 V=s;

# Copy the image of openwrt building to build folder.
	cp -v $(OPENWRTDOR)/bin/targets/bcm27xx/bcm2711/openwrt-bcm27xx-bcm2711-rpi-4-squashfs-factory.img.gz $(BUILDFOLDER)

pi_router/burn:
	rm -rfv $(BUILDFOLDER)/openwrt-bcm27xx-bcm2711-rpi-4-squashfs-factory.img
	gunzip -dk $(BUILDFOLDER)/openwrt-bcm27xx-bcm2711-rpi-4-squashfs-factory.img.gz
ifeq ($(TARGET_DISK),)
	@echo Variable TARGET_DISK is not empty.
else
	sudo dd if=$(BUILDFOLDER)/openwrt-bcm27xx-bcm2711-rpi-4-squashfs-factory.img of=$(TARGET_DISK) bs=1M
	sync
	@echo Burning complete
endif

pi_router/clean:
	$(MAKE) -C $(OPENWRTDOR) distclean;
	mkdir -rp build

.PHONY: all pi_router/beforebuild pi_router/build pi_router/clean pi_router/burn
