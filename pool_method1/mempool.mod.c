#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
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

SYMBOL_CRC(polloc, 0x0e2a72c4, "");
SYMBOL_CRC(pfree, 0x88e56f14, "");

static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x750ec835, "kmem_cache_alloc" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x45709afa, "kmem_cache_free" },
	{ 0x122c3a7e, "_printk" },
	{ 0xcd609647, "kmem_cache_create" },
	{ 0xd3c03786, "kmem_cache_size" },
	{ 0xd497d435, "kmem_cache_destroy" },
	{ 0xb3d1bec3, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "B5A2F5D440FD9538EBEA20D");
