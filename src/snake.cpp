#include "snake.h"   


Snake::Snake(int x,int y){
    s.push_back({x+1,y});
    s.push_back({x,y});
} 
 
void Snake::move(char m){

    int prevX=s[0].x;
    int prevY=s[0].y;

    if(m=='w') s[0].y-=1;
    if(m=='s') s[0].y+=1;
    if(m=='a') s[0].x-=1;
    if(m=='d') s[0].x+=1;

    for(int i=1;i<s.size();i++){

        int tempX=s[i].x;
        int tempY=s[i].y;

        s[i].x=prevX;
        s[i].y=prevY;
        prevX=tempX;            
        prevY=tempY;

        }
    }
    
void Snake:: eat(){
    segment tail=s.back();
    s.push_back(tail);
    }

const std::vector<segment>& Snake::getBody()const{
    return s;
    }

const segment& Snake::getHead()const{
     return s[0];
}