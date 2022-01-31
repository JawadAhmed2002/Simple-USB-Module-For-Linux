#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xb3753869, "module_layout" },
	{ 0x6b7ba003, "usb_deregister" },
	{ 0xbf671e22, "usb_register_driver" },
	{ 0xc5850110, "printk" },
	{ 0x3b823a96, "_dev_info" },
	{ 0xbdfb6dbb, "__fentry__" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v23A9pEF18d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "9368BD07589B688E5B73AB4");
