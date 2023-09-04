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


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x122c3a7e, "_printk" },
	{ 0xcd609647, "kmem_cache_create" },
	{ 0xd3c03786, "kmem_cache_size" },
	{ 0xb43f9365, "ktime_get" },
	{ 0xbdd7482e, "kmalloc_caches" },
	{ 0xa6302497, "kmalloc_trace" },
	{ 0x37a0cba, "kfree" },
	{ 0x750ec835, "kmem_cache_alloc" },
	{ 0x45709afa, "kmem_cache_free" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0xd497d435, "kmem_cache_destroy" },
	{ 0xb3d1bec3, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "6029688F43621F7D65F105B");
