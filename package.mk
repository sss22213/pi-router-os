curdir := package
package := $(wildcard ${curdir}/*)

define pi_router/package/preprocess
	$(foreach package_dir,$(package),$(MAKE) -C $(package_dir) preprocess;)
endef

define pi_router/package/build
	$(foreach package_dir,$(package),$(MAKE) -C $(package_dir) preprocess;)
endef

define pi_router/package/afterbuild
	$(foreach package_dir,$(package),$(MAKE) -C $(package_dir) preprocess;)
endef