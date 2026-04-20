#include <cstdlib>
#include <cstdio>
#include <atomic>
#include <csignal>
#include "game.hpp"

std::atomic<bool> running(true);

void HandleCancellation(const int arg_signal_number)
{
  static_cast<void>(arg_signal_number);
  running = false;
  printf("\nEnd of the game.\n");
  std::exit(1);
}

int main(int argc, char** argv)
{
  // Disable stdout buffering
#if (_DEBUG == 1)
  setbuf(stdout, NULL);
#endif

  cGame::GetInstance().Init();

  // End endless while-loop with Ctrl+C and call destructors
  std::signal(SIGINT, HandleCancellation);

  while (running)
  {
    cGame::GetInstance().Run();
  }

  return 0;
}
