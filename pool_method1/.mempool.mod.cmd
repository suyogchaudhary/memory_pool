cmd_/home/cj7/project/pool_method1/mempool.mod := printf '%s\n'   mempool.o | awk '!x[$$0]++ { print("/home/cj7/project/pool_method1/"$$0) }' > /home/cj7/project/pool_method1/mempool.mod
