#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/timekeeping.h>
#include<linux/slab.h>

#define POOL (1024 * 1024)                //100MB
#define CHUNK_SIZE 128
//#define MAX_ALLOC  (POOL / CHUNK_SIZE)                     //100MB(POOL) / 128(chunks) = 8192 pointers can get 128bytes memory allocations
#define MAX_ALLOC ((100 * 1024 * 1024)/(128))

MODULE_AUTHOR("230340130052");
MODULE_DESCRIPTION("Avg module");
MODULE_LICENSE("GPL");

void *polloc(void);
void pfree(void *);

struct kmem_cache *cache;


void **kmalloc_ptr, **polloc_ptr;                      //for array of pointers for allocations
signed long indx;                                              // for N number of objects allocations
long long time_before, time_after, time_taken_polloc, time_taken_kmalloc, time_taken;         //time stamps
void *mptr , *pptr;
static int __init demo_init(void)
{	
	
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	
	/*---------------------KMEM_CACHE_ALLOC-------------------------*/
	if(NULL == (cache = kmem_cache_create("Demo_pool", CHUNK_SIZE,0 ,SLAB_HWCACHE_ALIGN ,NULL))){
		printk(KERN_ALERT"CACHE CREATION FAIL!!!\n");
		return -ENOMEM;
		}
	             
	printk(KERN_ALERT"CACHE CREATION SUCCESSFULL!! Object size: %d   \n",kmem_cache_size(cache));
	
	
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	
	time_before = ktime_get_ns();
	for(indx = 0; indx < MAX_ALLOC; indx++){
		mptr = kmalloc(128, GFP_KERNEL);
		kfree(mptr);
	}
	time_after = ktime_get_ns();	
	time_taken_kmalloc = time_after - time_before;
	
	printk("KMALLOC : %lld\n", time_taken_kmalloc);
	
	
	
	time_before = ktime_get_ns();
	for(indx = 0; indx < MAX_ALLOC; indx++){
		mptr = 	kmem_cache_alloc(cache, GFP_KERNEL);
		kmem_cache_free(cache, mptr);
	}
	time_after = ktime_get_ns();
	time_taken_polloc = time_after - time_before;	
	
	printk("KMEM_CACHE_ALLOC : %lld\n", time_taken_polloc);
	
	
	
	time_before = ktime_get_ns();	
	
	
	time_taken = time_taken_kmalloc - time_taken_polloc;
	printk("TIME TAKEN : %lld\n", time_taken);
	
	
	/*----------------------------------------*/
	
	
	/*----------------------ONLY allocation---------------
	
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	time_before = ktime_get_ns();
	for(int indx = 0; indx < MAX_ALLOC; indx++){
		mptr = polloc();
	}
	time_after = ktime_get_ns();
	time_taken_polloc = time_after - time_before;	
	printk("POLLOC : %llu\n", time_taken_polloc);
	
	
	
	time_before = ktime_get_ns();	
	for(int indx = 0; indx < MAX_ALLOC; indx++){
		mptr = kmalloc(128, GFP_ATOMIC);
	}
	time_after = ktime_get_ns();	
	time_taken_kmalloc = time_after - time_before;
	printk("KMALLOC : %llu\n", time_taken_kmalloc);
	
	
	printk("TIME TAKEN : %lld\n", time_taken_kmalloc - time_taken_polloc);
	
	
	--------------------------*/
	
	/*-------------------ALLOC DEALLOC EACH TIME----------------
	
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	time_before = ktime_get_ns();
	for(int indx = 0; indx < MAX_ALLOC; indx++){
		mptr = polloc();
		pfree(mptr);
	}
	time_after = ktime_get_ns();
	time_taken_polloc = time_after - time_before;	
	printk("POLLOC : %llu\n", time_taken_polloc);
	
	
	
	time_before = ktime_get_ns();	
	for(int indx = 0; indx < MAX_ALLOC; indx++){
		mptr = kmalloc(128, GFP_ATOMIC);
		kfree(mptr);
	}
	time_after = ktime_get_ns();	
	time_taken_kmalloc = time_after - time_before;
	printk("KMALLOC : %llu\n", time_taken_kmalloc);
	
	
	printk("TIME TAKEN : %lld\n", time_taken_kmalloc - time_taken_polloc);
	
	
	--------------------------------*/
	
	return 0;
	
	
	

}

static void __exit demo_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	kmem_cache_destroy(cache);
	printk("CACHE DESTROYED!!\n");
	/*
	for( indx = 0; indx < MAX_ALLOC; ++indx){
		pfree(*(polloc_ptr + indx));
	}
	
	kfree(polloc_ptr);
	
	for( indx = 0; indx < MAX_ALLOC; ++indx){
		kfree(*(kmalloc_ptr + indx));
	}
	
	kfree(kmalloc_ptr);
	
	
	kfree(mptr);
	kfree(pptr);
	*/
}

module_init(demo_init);
module_exit(demo_exit);
