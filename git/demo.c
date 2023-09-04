#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/timekeeping.h>
#include<linux/slab.h>


MODULE_AUTHOR("Kishore Kumar");
MODULE_DESCRIPTION("Avg module");
MODULE_LICENSE("GPL");

void *polloc(void);
void pfree(void *);

static int avg_init(void)
{	
	long long time_before, time_after, time_taken;
	int i;
	void **ptr = kmalloc(8192 * sizeof(void *), GFP_KERNEL);
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
	time_before = ktime_get_ns();
	
	for( i = 0; i < 8192; ++i){
		*(ptr + i) = polloc();
		if (i == 0 || i == 81910){
			printk(" polloc allocated:%p %d\n",ptr[i], i);
		}
	}
	
	time_after = ktime_get_ns();
	time_taken = time_after - time_before;
	printk(" time_before:%llu time_after: %llu time_taken : %llu\n",time_before, time_after, time_taken);
	
 
	for( i = 0; i < 8192; ++i){
		pfree(*(ptr + i));
		//printk(" polloc freed:%p %d\n",ptr[i], i);
	}
	
	kfree(ptr);
	//pfree();
	return 0;
}

static void avg_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(avg_init);
module_exit(avg_exit);
