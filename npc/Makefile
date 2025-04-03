all: sim run

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator -Wall --cc vsrc/top.v --exe csrc/main.cpp --build

run:
	./obj_dir/Vtop

include ../Makefile
