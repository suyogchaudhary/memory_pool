#include<linux/module.h>
#include<linux/init.h>
#include<linux/kernel.h>

MODULE_AUTHOR("Suyog Chaudhary");
MODULE_DESCRIPTION("Avg module");
MODULE_LICENSE("GPL");

void *polloc(void);
void pfree(void *);

static int avg_init(void)
{	
	int i;
	void *ptr[5];
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);

	for( i = 0; i < 5; ++i){
		ptr[i] = polloc();
		printk(" polloc allocated:%p %d\n",ptr[i], i);
	}
	for( i = 0; i < 5; ++i){
		pfree(ptr[i]);
		printk(" polloc freed:%p %d\n",ptr[i], i);
	}

	//pfree();
	return 0;
}

static void avg_exit(void)
{
	printk("%s:%s:%d\n",__FILE__,__func__,__LINE__);
}

module_init(avg_init);
module_exit(avg_exit);
