curdir := package
#package := $(wildcard ${curdir}/*)

#define pi_router/package/preprocess
#	$(foreach package_dir,$(package),$(MAKE) -C $(package_dir) preprocess;)
#endef

#define pi_router/package/build
#	$(foreach package_dir,$(package),$(MAKE) -C $(package_dir) preprocess;)
#endef

#define pi_router/package/afterbuild
#	$(foreach package_dir,$(package),$(MAKE) -C $(package_dir) preprocess;)
#endef

define pi_router/package/build
	$(call pi_router/$(strip $(1))/beforebuild)
	$(call pi_router/$(strip $(1))/build)
	$(call pi_router/$(strip $(1))/afterbuild)
endef

