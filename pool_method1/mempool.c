#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/gfp.h>


#define CHUNK_SIZE 256                 

/*------------------------------------------------------------
  128bytes chunks size, for 100mb number of chunks = 819200
  ----------------------------------------------------------*/
MODULE_AUTHOR("230340130052");
MODULE_DESCRIPTION("Naive memory pool");
MODULE_LICENSE("GPL");



struct kmem_cache *cache;


void *polloc(void)
{
	return kmem_cache_alloc(cache, GFP_ATOMIC);
}

void pfree(void *mem_ptr)
{
	kmem_cache_free(cache, mem_ptr);
}

EXPORT_SYMBOL(polloc);
EXPORT_SYMBOL(pfree);

static int __init pool_init(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	if(NULL == (cache = kmem_cache_create("Demo_pool", CHUNK_SIZE,0 ,SLAB_HWCACHE_ALIGN ,NULL))){
		printk(KERN_ALERT"CACHE CREATION FAIL!!!\n");
		return -ENOMEM;
		}
	             
	printk(KERN_ALERT"CACHE CREATION SUCCESSFULL!! Object size: %d   \n",kmem_cache_size(cache));
	return 0;
}


static void __exit pool_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	kmem_cache_destroy(cache);
	printk("CACHE DESTROYED!!\n");
}


module_init(pool_init);
module_exit(pool_exit);












