int main(void) {
  volatile int a = 10;
  volatile int b = 20;
  volatile int c = a + b;

  // Update ready bit in MSG REG (64-bit)
  volatile unsigned long long *MSG_REG = (volatile unsigned long long *)0x50009;

  volatile unsigned long long val = *MSG_REG;
  val |= (1ULL << 63); // set bit 63
  *MSG_REG = val; // store 64-bit value

  // infinite loop
  while (1)
    ;
  return c;
}
