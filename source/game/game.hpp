#ifndef GAME_HPP
#define GAME_HPP

#include "display.hpp"

class cGame
{
public:
  static cGame& GetInstance(void);
  void Init(void);
  void Run(void);

private:
  enum class eState
  {
    E_START,
    E_WAIT_INPUT,
    E_CHECK_INPUT,
    E_CELEBRATION,
  };

  cGame(void);

  void HandleStateStart(void);
  void HandleStateWaitInput(void);
  void HandleStateCheckInput(void);
  void HandleStateCelebration(void);

  eState state;
  cDisplay display;
  uint8_t number;
  uint8_t guess;
  uint8_t attempts;
};

#endif
