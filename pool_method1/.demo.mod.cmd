cmd_/home/cj7/project/pool_method1/demo.mod := printf '%s\n'   demo.o | awk '!x[$$0]++ { print("/home/cj7/project/pool_method1/"$$0) }' > /home/cj7/project/pool_method1/demo.mod
