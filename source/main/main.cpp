#include <cstdlib>
#include <cstdio>
#include <atomic>
#include <csignal>

std::atomic<bool> running(true);

void HandleCancellation(const int arg_signal_number)
{
  static_cast<void>(arg_signal_number);
  running = false;
}

int main(int argc, char** argv)
{
  // Disable stdout buffering
#if (_DEBUG == 1)
  setbuf(stdout, NULL);
#endif

  // End endless while-loop with Ctrl+C and call destructors
  std::signal(SIGINT, HandleCancellation);
  uint32_t counter = 0U;

  // I2C address is 0x68
  // Standard and fast mode supported
  // Only 7-bit address mode

  while (running)
  {
    printf("%u\n", counter);
    counter++;
    sleep(1U);
  }

  return 0;
}
