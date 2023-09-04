#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/timekeeping.h>
#include <linux/slab.h>

#define CHUNKS 8

MODULE_AUTHOR("Suyog Chaudhary");
MODULE_DESCRIPTION("Avg module");
MODULE_LICENSE("GPL");

void *polloc(void);
void pfree(void *);

static int avg_init(void)
{	
	long long time_before, time_after, time_taken;
	int i;
	void *ptr[CHUNKS];
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	time_before = ktime_get_ns();

	for( i = 0; i < CHUNKS; ++i){
		ptr[i] = kmalloc(128, GFP_KERNEL);
		//printk(" kmalloc allocated:%p %d\n",ptr[i], i);
	}
	time_after = ktime_get_ns();
	time_taken = time_after - time_before;
	printk(" time_before:%llu time_after: %llu time_taken : %llu\n",time_before, time_after, time_taken);
	
  	
	for( i = 0; i < CHUNKS; ++i){
		kfree(ptr[i]);
		//printk(" kmalloc freed:%p %d\n",ptr[i], i);
	}
	return 0;
}

static void avg_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(avg_init);
module_exit(avg_exit);
