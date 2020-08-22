#pragma once

int map_x = 0;
int map_y = 0;


#define WORLD_WIDTH    14 //14
#define WORLD_HEIGHT  10 //7
#define TileSize 16

/*#define GRASS      0
#define WATER      1
#define TREES      2
#define STONE      3*/

#define WATER 0
#define SAND 1
#define PATH 2
#define STONE 3
#define TREE 4
#define WOOD 5
#define BRICK 6
#define GRASS 7

int world[WORLD_HEIGHT][WORLD_WIDTH] = {
  { SAND, WATER, WATER, WATER, SAND, PATH, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,},
  { SAND, WATER,SAND,WATER,/**/WOOD, PATH, GRASS, STONE, GRASS, WOOD, WOOD, WOOD, WOOD, WOOD,/**/},
  { SAND, WATER, WATER, WATER, SAND, PATH, GRASS, GRASS, GRASS, WOOD, BRICK, BRICK, BRICK, WOOD,},
  { SAND, SAND, SAND, SAND,/**/SAND, PATH, PATH, PATH, PATH, WOOD, BRICK, BRICK, BRICK, WOOD,},
  { GRASS,GRASS,GRASS, GRASS, GRASS, PATH, GRASS, GRASS, GRASS, WOOD, BRICK, BRICK, BRICK, WOOD,},
  { GRASS,STONE,GRASS, GRASS, GRASS, PATH, GRASS, GRASS, TREE, WOOD, WOOD, WOOD, WOOD, WOOD,},
  { WATER,WOOD,WATER, WATER, GRASS, PATH, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS, GRASS,},
  { SAND,SAND,SAND, WATER, GRASS, PATH, GRASS, GRASS, GRASS, GRASS, TREE, TREE, GRASS, GRASS,},
  { SAND,SAND,SAND, WATER, WATER, WOOD, WATER, WATER, WATER, GRASS, TREE, TREE, GRASS, GRASS,},
  { SAND,SAND,SAND, SAND, SAND, PATH, SAND, SAND, WATER, WATER, WATER, WATER, SAND, SAND,},
};

#define TILE_SIZE  16

void drawWorld() {
  const int tileswide = WIDTH / TILE_SIZE + 1;
  const int tilestall = HEIGHT / TILE_SIZE + 1;

  for (int y = 0; y < tilestall; y++) {
    for (int x = 0; x < tileswide; x++) {
      const int tilex = x - map_x / TILE_SIZE;
      const int tiley = y - map_y / TILE_SIZE;
      if (tilex >= 0 && tiley >= 0 && tilex < WORLD_WIDTH && tiley < WORLD_HEIGHT) {
        Sprites::drawOverwrite(x * TILE_SIZE + map_x % TILE_SIZE, y * TILE_SIZE + map_y % TILE_SIZE, tiles, world[tiley][tilex]);
      }
    }
  }
}
