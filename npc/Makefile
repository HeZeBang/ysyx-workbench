NEMU_HOME=$(cwd)

all:
	sim

sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	verilator --cc --exe --build -Wall vsrc/example.v csrc/main.cpp

include ../Makefile
