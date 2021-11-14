#ifndef LOAD_SAVE_H
#define LOAD_SAVE_H

#include "wordmachine.h"
#include "game.h"
#include "listdin.h"
#include "queue.h"

extern Game data;

void load(int type);

void save();

#endif