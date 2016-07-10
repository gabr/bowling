// bowling_game_test.c
#include "bowling_game.h"

#include "assert.h"
#include <stdbool.h>

static void test_gutter_game()
{
  int i;

  bowling_game_init();
  for (i = 0; i < 20; i++)
    bowling_game_roll(0);

  assert(bowling_game_score() == 0 && "test_gutter_game()");
}

int main(void)
{
  test_gutter_game();

  return 0;
}

