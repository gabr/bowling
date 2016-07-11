// bowling_game.c
#include "bowling_game.h"

enum { max_rolls = 21, frames_count = 10 };
static int rolls[max_rolls];
static int current_roll;

void bowling_game_init()
{
  int i;
  for (i = 0; i < max_rolls; i++)
    rolls[i] = 0;
  current_roll = 0;
}

void bowling_game_roll(int pins)
{
  rolls[current_roll++] = pins;
}

static bool is_spare(int frame_index)
{
  return rolls[frame_index] + rolls[frame_index+1] == 10;
}

static bool is_strike(int frame_index)
{
  return rolls[frame_index] == 10;
}

static int strike_score(int frame_index)
{
  return 10 + rolls[frame_index+1] + rolls[frame_index+2];
}

static int spare_score(int frame_index)
{
  return 10 + rolls[frame_index+2];
}

static int normal_score(int frame_index)
{
  return rolls[frame_index] + rolls[frame_index+1];
}

int bowling_game_score()
{
  int frame_index, frame, score;
  frame_index = frame = score = 0;

  for (frame = 0; frame < frames_count; ++frame)
  {
    if (is_spare(frame_index))
    {
      score += spare_score(frame_index);
      frame_index += 2;
    }
    else if (is_strike(frame_index))
    {
      score += strike_score(frame_index);
      frame_index += 1;
    }
    else // normal
    {
      score += normal_score(frame_index);
      frame_index += 2;
    }
  }

  return score;
}

