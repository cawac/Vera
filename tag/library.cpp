#ifndef PROJECT_LIBRARY_H
#define PROJECT_LIBRARY_H
#include "library.h"
#endif //PROJECT_LIBRARY_H

field::field() {

}

bool field::operator == ( int a) {
    return this->getNumber() == a;
}

field::field(int number) {

}

int field::getNumber() const {
    return number;
}

void field::setNumber(int number) {
    field::number = number;
}

game::game() {
    table= new field* [n];
    for (int i = 0; i < n; ++i) {
        table[i]= new field[n];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(!(i==n-1 && j==n-1))
                second[i][j].setNumber(n*i+1+j);
            else
                second[i][j].setNumber(0);
        }
    }
}

game::~game() {
    for (int i = 0; i < n; ++i) {
        delete [] this->table[i];
    }
    delete [] table;
}

void game::create() {// make the initial tag
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            table[i][j].setNumber(second[i][j].getNumber());
        }
    }
    place_of_zero_y=3;
    place_of_zero_x=3;
    int key1, key2 = -1;
    for (int i = 0; i < 1000000; ++i) {
        key1 = rand() % 4;
        if (key1 != key2)
            switch (key1) {
                case 0:
                    if(place_of_zero_x+1!=4)move(table[place_of_zero_x+1][place_of_zero_y].getNumber());break;
                case 1:
                    if(place_of_zero_x-1!=-1)move(table[place_of_zero_x-1][place_of_zero_y].getNumber());break;
                case 2:
                    if(place_of_zero_y+1!=4)move(table[place_of_zero_x][place_of_zero_y+1].getNumber());break;
                case 3:
                    if(place_of_zero_y-1!=-1)move(table[place_of_zero_x][place_of_zero_y-1].getNumber());break;
            }
        else
            i--;
        key2 = key1;
    }
    if (wincondition())
        create();
}

bool game::wincondition() { //check the winning condition
    bool key= false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(table[i][j]==second[i][j].getNumber() )
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

void game::set_x_y() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (table[i][j]==0)
            {
                place_of_zero_x=j;
                place_of_zero_y=i;
                return;
            }
        }
    }

}

void game::move(int changefield) {

    if ((place_of_zero_x+1)!=n)
        if (table[place_of_zero_y][place_of_zero_x+1]==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_x++;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
    if ((place_of_zero_x-1)!=-1)
        if (table[place_of_zero_y][place_of_zero_x-1]==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_x--;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
    if(place_of_zero_y+1!=n)
        if (table[place_of_zero_y+1][place_of_zero_x]==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_y++;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
    if(place_of_zero_y-1!=-1)
        if (table[place_of_zero_y-1][place_of_zero_x]==changefield)
        {
            this->table[place_of_zero_y][place_of_zero_x].setNumber(changefield);
            this->place_of_zero_y--;
            this->table[place_of_zero_y][place_of_zero_x].setNumber(0);
            return;
        }
}

std::ostream& operator<<(std::ostream &out, game &game) {
    for (int i = 0; i < game::n; ++i) {
        for (int j = 0; j < game::n; ++j) {
            out << std::setw(4)<< game.table[i][j].getNumber();
        }
        out << "\n";
    }
    return out;
}