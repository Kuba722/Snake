#include "map.h"

GameMap::GameMap(int w, int h){
    width=w;
    height=h;
}
int GameMap::getWidth(){
    return width;
}
int GameMap::getHeight(){
    return height;
}
