#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
//#include <library.cpp>
using namespace std;
class field{
public:
    int x,y,number;
};
class game{
public:
    const int n=4;
    field **table=NULL;//place of 0
    game(){
        table=new field*[n];
        for (int i = 0; i < n; ++i) {
            table[i]=new field[n];
        }
    }
    ~game(){
        for (int i = 0; i < n; ++i) {
            delete [] table[i];
        }
        delete [] table;
    }
    void recursion(int i){// filling empty`s places
        int k=rand()%4;
        int j=rand()%4;
        if(table[k][j].number==0)// filling [k][j] place in tag
        {
            table[k][j].number=i;
            table[k][j].x=j;
            table[k][j].y=k;
        }
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
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout<<setw(4)<<table[i][j].number;
            }
            cout<<"\n";
        }
    }
    bool wincondition(){ //check the winning condition
        bool key=true;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (table[3][3].number==0 )//mean that all must be in their positions and last 0
                    if(table[i][j].number!=4*i+j+1)
                    {
                        key=false;
                        break;
                    }
                else
                    break;
            }
        }
        return key;
    }/*
    void set_x_y(){
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (table[i][j]==0)
                    x=j;
                    y=i;
            }
        }

    }*/
    void move(){/*
        int buffer;
        if (x!=3)
            if (x!=0)
                if (y!=0)
                    if (y!=3)
                    {
                        cout<<table[y][x+1]<<table[y][x-1]<<table[y+1][x]<<table[y-1][x];
                        cin>>buffer;

                    }
    */}
};
int main() {
    srand(time(NULL));
    game tag;
    tag.create();
    tag.show();
   // tag.set_x_y();
    while (!tag.wincondition()) {
        tag.move();
        tag.show();
    }
    cout<<"you are the champion!)";
    return 0;
}
