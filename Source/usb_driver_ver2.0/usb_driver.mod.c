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
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0xe6278ff5, "__register_chrdev" },
	{ 0xb44ad4b3, "_copy_to_user" },
	{ 0x6b7ba003, "usb_deregister" },
	{ 0xc5850110, "printk" },
	{ 0x3b823a96, "_dev_info" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xbf671e22, "usb_register_driver" },
	{ 0x88db9f48, "__check_object_size" },
};

MODULE_INFO(depends, "");

MODULE_ALIAS("usb:v23A9pEF18d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "3C3A5487115F827C3CC7B4B");
