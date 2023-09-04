#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/mempool.h>

#define POOL_SIZE 1024
#define CHUNK_SIZE 256

MODULE_AUTHOR("230340130052");
MODULE_DESCRIPTION("Naive memory pool");
MODULE_LICENSE("GPL");

struct memory_pool{
	int       min_chunks;
	int       curr_chunks;
	struct    kmem_cache *cache;
	int       chunk_size;
	int       pool_size;
	void      *pool;
	int       *bitmap;
	int       alloc_chunks;
}mem_pool;

void *polloc(void)
{
	/*
	int indx = 0;
	//printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	while(mem_pool.bitmap[indx] == 1){
		++indx;
	}
	mem_pool.bitmap[indx] = 1;
	//printk("POLLOC called ,bitmap index:%d\n", indx);

	return (char *)(mem_pool.pool + (CHUNK_SIZE * indx));
	
	*/
	

	return kmem_cache_alloc(mem_pool.cache, GFP_KERNEL);
}

void pfree(void *mem_ptr)
{
	/*
	int indx;
	//printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	indx = (mem_ptr - mem_pool.pool ) / CHUNK_SIZE;
	mem_pool.bitmap[indx] = 0;
	//printk("POLLOC free ,bitmap index:%d\n", indx);
	*/
	kmem_cache_free(mem_pool.cache, mem_ptr);
}

EXPORT_SYMBOL(polloc);
EXPORT_SYMBOL(pfree);

static int __init pool_init(void)
{
	//int i = 0;
	//mem_pool.min_chunks = POOL_SIZE / CHUNK_SIZE;
	//mem_pool.curr_chunks = POOL_SIZE / CHUNK_SIZE;
	mem_pool.cache = mempool_create(8192, mempool_alloc_slab, mempool_free_slab, NULL);
	//mem_pool.chunk_size = CHUNK_SIZE;
	//mem_pool.pool_size = POOL_SIZE;
	//mem_pool.bitmap = kmalloc(mem_pool.curr_chunks * sizeof(int), GFP_KERNEL);
	//for(i = 0; i < mem_pool.curr_chunks; ++i){
	//	mem_pool.bitmap[i] = 0;
		//printk(KERN_ALERT"mem_pool.bitmap[%d]: %d\n",i,mem_pool.bitmap[i]);
	//}
	//mem_pool.pool  = kmem_cache_alloc(mem_pool.cache, GFP_KERNEL);	
	printk(KERN_ALERT"cache pool size: %d\n",kmem_cache_size(mem_pool.cache));
	//printk(KERN_ALERT"cache pool add: %p\n",mem_pool.pool);
	return 0;
}


static void __exit pool_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	//kfree(mem_pool.bitmap);
	//kmem_cache_free(mem_pool.cache, mem_pool.pool);
	kmem_cache_destroy(mem_pool.cache);
	printk("cache destroyed successful\n");
}


module_init(pool_init);
module_exit(pool_exit);












