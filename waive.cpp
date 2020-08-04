#include <stdbool.h>
#include <stdio.h>

#define DC 0xfffffff

typedef enum Op { NOP = 0, FEYNMAN, FREDKIN } Op;

typedef struct Code {
  Op opcode;
  int a, b, c, d;
} Code;

typedef struct Machine {
  // Operands
  bool a;
  bool b;
  bool c;
  bool d;

  // Memory
  bool mem[32];

  // Call stack
  Code instructions[32];
  int instruction_count;

} Memory;

void fredkin(Machine *m) {
  bool p, q, r;

  p = m->a;
  q = (!m->a && m->b) || (m->a && m->c);
  r = (m->a && m->b) || (!m->a && m->c);

  m->a = p;
  m->b = q;
  m->c = r;
}

void feynman(Machine *m) {
  bool p, q;

  p = m->a;
  q = m->a xor m->b;

  m->a = p;
  m->b = q;
}

void tiffoli(Machine *m) {
  bool p, q, r;

  p = m->a;
  q = m->b;
  r = (m->a && m->b) xor m->c;

  m->a = p;
  m->b = q;
  m->c = r;
}

void fetch(Machine *m, int a, int b, int c, int d) {
  if (a != DC) m->a = m->mem[a];
  if (b != DC) m->b = m->mem[b];
  if (c != DC) m->c = m->mem[c];
  if (d != DC) m->d = m->mem[d];
}

void write(Machine *m, int a, int b, int c, int d) {
  if (a != DC) m->mem[a] = m->a;
  if (b != DC) m->mem[b] = m->b;
  if (c != DC) m->mem[c] = m->c;
  if (d != DC) m->mem[d] = m->d;
}

void call(Machine *m, Op opcode, int a, int b, int c, int d) {
  fetch(m, a, b, c, d);

  if (opcode == FEYNMAN) {
    feynman(m);  // a
  } else if (opcode == FREDKIN) {
    fredkin(m);  // a
  }

  write(m, a, b, c, d);
}

void printmem(Machine *m, int count) {
  for (int i = 0; i < count; i++) {
    printf("%i", m->mem[i]);
  }
  printf("\n");
}

void push(Machine *m, bool verbose) {
  int i = 0;
  Code c = m->instructions[i];

  while (c.opcode != NOP) {
    call(m, c.opcode, c.a, c.b, c.c, c.d);
    if (verbose) {
      printf("%i| %i: %i %i %i %i\n", i, c.opcode, c.a, c.b, c.c, c.d);
      printmem(m, 6);
    }
    c = m->instructions[++i];
    m->instruction_count = i;
  }
}

void pull(Machine *m, bool verbose) {
  for (int i = m->instruction_count; i > 0; i--) {
    Code c = m->instructions[i - 1];
    call(m, c.opcode, c.a, c.b, c.c, c.d);
    if (verbose) {
      printf("%i| %i: %i %i %i %i\n", i - 1, c.opcode, c.a, c.b, c.c, c.d);
      printmem(m, 6);
    }
  }
}
