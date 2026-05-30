#include"food.h"


Food::Food(){
    x=rand()%10; 
    y=rand()%10;
}

void Food::setX(int t_x){
    if(t_x<0){
        std::cout<<"You can't set x to "<<t_x<<std::endl;
    }else{
        x=t_x;
    }
}

void Food::setY(int t_y){
    if(t_y<0){
        std::cout<<"You can't set y to "<<t_y<<std::endl;
    }else{
        y=t_y;
    }
}

int Food::getX() const{
    return x;
}

int Food::getY() const{
    return y;
}

