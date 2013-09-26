#include <ncurses.h>
#include "snake.h"
#include <stdio.h>
#include <stdlib.h>

enum Direction { UP, DOWN, LEFT, RIGHT };
enum Status { SUCCESS, FAIL };

struct Snake {
  int x;
  int y;
  struct Snake* next;
};

void display_snake(struct Snake* snake) {
  while(snake) {
    mvprintw(snake->x, snake->y, "#");
    snake = snake->next;
  }

}

enum Status move_snake(struct Snake* snake, enum Direction dir) {
  return FAIL;
  struct Snake* start = snake;
  // Go to the end
  while(snake->next) {
    snake = snake->next;
  }
  free(snake);
}


struct Snake* next_move(int x, int y, enum Direction dir) {
  if (dir == LEFT && x == 0) {
    return NULL;
  } else if (dir == UP && y == 0) {
    return NULL;
  }
}

struct Snake* create_cell(int x, int y) {
  struct Snake* cell = malloc(sizeof(*cell));
  cell->x = x;
  cell->y = y;
  cell->next = NULL;
  return cell;
}

struct Snake* create_snake() {
  struct Snake* a = create_cell(2,3);
  struct Snake* b = create_cell(2,2);
  a->next = b;
  return a;
}

enum Direction get_next_move() {
  return UP;
}

int main() {
  initscr();
  curs_set(0); // hide cursor

  struct Snake *snake = create_snake();

  while(true) {
    display_snake(snake);
    enum Direction dir = get_next_move();
    enum Status status = move_snake(snake, dir);
    if (status == FAIL) break;
  }

  //getmaxyx(stdscr, y, x);
  getch();
  //printf("Size: %d %d", x, y);
  return 0;
}
