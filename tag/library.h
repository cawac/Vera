#ifndef TAG_LIBRARY_H
#define TAG_LIBRARY_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
using namespace std;

class field{
private:
    int number;
public:
    void setNumber(int number);
    int getNumber() const;
};
field operator == (field b,int a){
    b.setNumber(a);
    return b;
}
class game{
private:
    field **table;
    static const int n=4;
    int place_of_zero_x{},place_of_zero_y{};//place of 0
public:
    game(){
        table= new field* [n];
        for (int i = 0; i < n; ++i) {
            table[i]= new field[n];
        }
    }
    ~game(){
        for (int i = 0; i < n; ++i) {
            delete [] this->table[i];
        }
        delete [] table;
    }
    void recursion(int i){// filling empty`s places
        int k=rand()%n;
        int j=rand()%n;
        if(table[k][j].getNumber()==0)// filling [k][j] place in tag
        {
            table[k][j].setNumber(i);
        }
        else
        {
            recursion(i);//repeat, if place is not empty
        }
    }
    void create(){// make the initial tag
        for (int i = 1; i < n*n; ++i) {
            recursion(i);// filling empty`s places with numbers in range 1 ... 15
        }
    }
    void show(){// output of tag
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout<<setw(4)<<table[i][j].getNumber();
            }
            cout<<"\n";
        }
    }
    bool wincondition(){ //check the winning condition
        bool key= false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (table[n-1][n-1].getNumber()==0 )//mean that all must be in their positions and last 0
                    if(table[i][j].getNumber()==n*i+j+1 && (i!=n-1 && j!=n-1))
                    {
                        key=true;
                    }
                    else
                    {
                        key=false;
                        return key;
                    }
            }
        }
        return key;
    }
    void set_x_y(){
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (table[i][j].getNumber()==0)
                {
                    place_of_zero_x=j;
                    place_of_zero_y=i;
                    return;
                }
            }
        }

    }
    void move(){
        int changefield;
        cin>>changefield;
        if ((place_of_zero_x+1)!=n)
        if (table[place_of_zero_y][place_of_zero_x+1].getNumber()==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_x++;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
        if ((place_of_zero_x-1)!=-1)
        if (table[place_of_zero_y][place_of_zero_x-1].getNumber()==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_x--;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
        if(place_of_zero_y+1!=n)
        if (table[place_of_zero_y+1][place_of_zero_x].getNumber()==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_y++;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
        if(place_of_zero_y-1!=-1)
        if (table[place_of_zero_y-1][place_of_zero_x].getNumber()==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_y--;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
    }
};
#endif //TAG_LIBRARY_H
