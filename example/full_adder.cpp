#include "../waive.cpp"

int main() {
  Machine m = {};
  bool a = 1;
  bool b = 1;
  bool c = 0;

  m.mem[0] = a;
  m.mem[1] = b;
  m.mem[2] = 0;
  m.mem[3] = c;
  m.mem[4] = 1;
  m.mem[5] = 0;

  printf("test\n\n");

  m.instructions[0] = {FREDKIN, 3, 4, 5, DC};
  m.instructions[1] = {FEYNMAN, 1, 2, DC, DC};
  m.instructions[2] = {FREDKIN, 0, 1, 3, DC};
  m.instructions[3] = {FREDKIN, 2, 4, 5, DC};
  m.instructions[4] = {FREDKIN, 2, 1, 3, DC};
  m.instructions[5] = {FREDKIN, 0, 4, 5, DC};
  m.instruction_count = 6;

  printf("init: ");
  printmem(&m, 6);
  printf("\n");

  printf("push:\n");
  push(&m, true);

  printf("\nsum:\t%i\n", m.mem[5]);
  printf("carry:\t%i\n\n", m.mem[1]);

  printf("pull:\n");
  pull(&m, true);

  printf("end: ");
  printmem(&m, 6);
  printf("\n");
}
