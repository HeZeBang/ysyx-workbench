#include "Vtop.h"
#include "verilated.h"
#include "verilated_vcd_c.h"  // 添加波形支持
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  VerilatedContext *contextp = new VerilatedContext;
  contextp->commandArgs(argc, argv);
  contextp->traceEverOn(true);  // 启用波形追踪

  Vtop *top = new Vtop{contextp};

  // 创建 VCD 波形追踪对象
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace(tfp, 99);          // 设置追踪深度
  tfp->open("wave.vcd");        // 打开波形文件

  while (!contextp->gotFinish()) {
    int a = rand() & 1;
    int b = rand() & 1;
    top->a = a;
    top->b = b;

    top->eval();                      // 模块求值
    tfp->dump(contextp->time());      // 输出当前时刻波形
    contextp->timeInc(1);            // 时间递增

    printf("a = %d, b = %d, f = %d\n", a, b, top->f);
    assert(top->f == (a ^ b));
  }

  tfp->close();          // 关闭波形文件
  delete tfp;
  delete top;
  delete contextp;
  return 0;
}
