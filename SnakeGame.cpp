#include <iostream>
#include <conio.h>  // For _kbhit() and _getch()
#include <cstdlib>  // For rand()
#include <ctime>    // For time()
#include <windows.h>
using namespace std;
bool gameOver;
int width = 20;
int height = 20;
int x , y , fx , fy , score , nTail;
int tailX[100] , tailY[100];
int tailLen = 0;
enum edirection {STOP = 0, LEFT , RIGHT , UP , DOWN};
edirection dir;
void setup() {
    gameOver = false;
    dir = STOP;
    x = width/2;
    y = width/2;
    fx = rand() % width;
    fy = rand() % height;
    score = 0;
}

void draw() {
    system("cls");
    for(int i =0 ; i<width+2 ; i++) {
        cout<<"_";
    }
    cout<<endl;
    for(int i =0 ; i<height ; i++ ) {
        for(int j =0 ; j<width; j++) {
            if(j==0) {
                cout<<"|";
            }
            if(i==y && j==x) {
                cout<<"O";
            }
            else if(i==fy && j==fx) {
                cout<<"F";
            }
            else {
                bool print = false;
                for(int k =0 ; k<tailLen; k++) {
                    if(tailX[k]==j && tailY[k]==i){
                        cout<<"o";
                        print = true;
                        break;
                    }
                }
                if(!print) {
                    cout<<" ";
                }
            }
            if(j==width-1){
                cout<<"|";
            }
            
        }
        cout<<endl;
    }
    for(int i =0 ; i<width ; i++) {
        cout<<"_";
    }
}
void Input() {
    if(_kbhit()) {
        switch(getch()) {
            case 'u':
            dir = UP;
            break;
            
            case 'd':
            dir = DOWN;
            break;
            case 'l':
            dir = LEFT;
            break;
            case 'r':
            dir = RIGHT;
            break;
            case 'q':
            gameOver = true;
            break;
            default:
            break;
        }
    }
}

void logic() {
    for(int i = tailLen-1 ; i>0 ; i-- ){
        tailX[i] = tailX[i-1];
        tailY[i] = tailY[i-1];
    }
    tailX[0] = x;
    tailY[0] = y;
    switch(dir) {
        case STOP:
        break;
        case LEFT:
        x--;
        break;
        case RIGHT:
        x++;
        break;
        case UP:
        y--;
        break;
        case DOWN:
        y++;
        break;
        default:
        break;
    }
    if(x<0 || x>width || y>height || y<0) {
        gameOver = true;
    }
    if(x==fx && y ==fy) {
        score+=10;
        fx = rand() % width;
        fy = rand() % height;
        tailLen++;
    }
}
int main() {
        setup();
        while(!gameOver){
           draw();
           Input();
           logic();
           Sleep(500);
        }   
}
