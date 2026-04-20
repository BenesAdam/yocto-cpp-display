#include <cstdlib>
#include <cstdio>
#include <atomic>
#include <csignal>
#include "display.hpp"

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

  cDisplay display;
  display.Init(0x27U);

  // End endless while-loop with Ctrl+C and call destructors
  std::signal(SIGINT, HandleCancellation);
  uint32_t counter = 0U;

  while (running)
  {
    printf("%u\n", counter);
    display.Clear();
    display.Home();
    display.Print(L"Hello world!\n");
    display.Print(L"Seconds: ");
    display.Print(counter);

    sleep(1U);
    counter++;
  }

  return 0;
}
