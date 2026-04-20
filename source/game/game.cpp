#include <unistd.h>
#include <stdio.h>
#include <random>
#include <ctime>
#include "game.hpp"

cGame::cGame(void) :
  state(eState::E_START),
  display(),
  number(0U),
  guess(0U),
  attempts(0U)
{
}

cGame& cGame::GetInstance(void)
{
  static cGame instance;
  return instance;
}

void cGame::Init(void)
{
  std::srand(std::time(0));
  display.Init(0x27U);
}

void cGame::Run(void)
{
  switch (state)
  {
  case eState::E_START:
    HandleStateStart();
    break;
  case eState::E_WAIT_INPUT:
    HandleStateWaitInput();
    break;
  case eState::E_CHECK_INPUT:
    HandleStateCheckInput();
    break;
  case eState::E_CELEBRATION:
    HandleStateCelebration();
    break;
  }
}

void cGame::HandleStateStart(void)
{
  attempts = 0U;
  number = (std::rand() % 100U) + 1U;

  display.Clear();
  display.Home();

  display.Print(L"Guess number in\n");
  display.Print(L"the range 1-100\n");

#if _GAME_DEBUG == 1
  printf("Debug: %hhu\n", number);
#endif

  printf("Gues number in the range 1-100: ");

  state = eState::E_WAIT_INPUT;
}

void cGame::HandleStateWaitInput(void)
{
  scanf("%hhu", &guess);

  state = eState::E_CHECK_INPUT;
}

void cGame::HandleStateCheckInput(void)
{
  display.Clear();
  attempts++;

  if (number != guess)
  {
    if (number < guess)
    {
      display.Print(L"Number is lower \n");
      printf("Number is lower. ");
    }
    if (number > guess)
    {
      display.Print(L"Number is higher\n");
      printf("Number is higher. ");
    }

    display.Print(L"Try again...    \n");
    printf("Try again: ");
    state = eState::E_WAIT_INPUT;
  }
  else
  {
    state = eState::E_CELEBRATION;
  }
}

void cGame::HandleStateCelebration(void)
{
  printf("Congratulation! You won!\n");
  printf("It takes %hhu attempts.\n", attempts);

  for (uint8_t i = 0U; i < 3U; i++)
  {
    display.Clear();
    display.Print(L"Congratulation! \n");
    display.Print(L"    You won!    \n");
    sleep(1U);
    display.Clear();
    display.Print(L"No. attempts:   \n");
    display.Print(static_cast<uint32_t>(attempts));
    sleep(1U);
  }

  state = eState::E_START;
}
