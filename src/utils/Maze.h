#ifndef Maze_h
#define Maze_h

#include <iostream>
#include "Mouse.h"

const int WIDTH = 5, HEIGHT = 5;

const int UP = 0, DOWN = 1, LEFT = 2, RIGHT = 3;

const char WAY = '.', WALL = '|', TARGET = 'Q', ENTRYPOINT = 'E', MOUSE = 'M';

struct Scene {
  char maze[WIDTH][HEIGHT] = {
    WAY, WALL, WAY, WAY, WALL,
    WAY, WALL, WAY, WAY, WAY,
    WALL, WAY, WAY, TARGET, WAY,
    WAY, WAY, WALL, WAY, WAY,
    WAY, WAY, WAY, WAY, WAY
  };
};

Scene createRandomlyEntrypoint(Scene &scene, Rat &rat) {
  int mazeAlreadyInitialized = 1;

  while(mazeAlreadyInitialized) {
    std::srand(time(NULL));

    int randomPositionAxisX = std::rand() % WIDTH, randomPositionAxisY = std::rand() % HEIGHT;

    if (
      scene.maze[randomPositionAxisX][randomPositionAxisY] != WALL and
      scene.maze[randomPositionAxisX][randomPositionAxisY] != TARGET
    ) {
      scene.maze[randomPositionAxisX][randomPositionAxisY] = ENTRYPOINT;
      rat.axisX = randomPositionAxisX;
      rat.axisY = randomPositionAxisY;

      mazeAlreadyInitialized = 0;
    }
  }

  return scene;
}

#endif
