#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;
enum direction{
    UP,DOWN,LEFT,RIGHT
};
class game{
private:
    int table [4][4]={//matrix view of tag
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0},
            {0,0,0,0}
    };
public:
    void recursion(int i){// filling empty`s places
        int k=rand()%4;
        int j=rand()%4;
        if(this->table[k][j]==0)// filling [k][j] place in tag
            this->table[k][j]=i;
        else
        {
            recursion(i);//repeat, if place is not empty
        }
    };
    void create(){// make the initial tag
        for (int i = 1; i < 16; ++i) {
            recursion(i);// filling empty`s places with numbers in range 1 ... 15
        }
    }
    void show(){// output of tag
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout<<setw(4)<<this->table[i][j];
            }
            cout<<"\n";
        }
    }

    bool wincondition(){ //check the winning condition
        bool key=true;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (this->table[3][3]==0 )//mean that all must be in their positions and last 0
                    if(this->table[i][j]!=4*i+j+1)
                    {
                        key=false;
                        break;
                    }
                else
                    break;
            }
        }
        return key;
    }
    void move(){//tomorrow)

    }
};
int main() {
    srand(time(NULL));
    game tag;
    tag.create();
    tag.show();
    while (!tag.wincondition()) {
        tag.move();
        tag.show();
    }
    cout<<"you are the champion!)";
    return 0;
}
