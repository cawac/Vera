#ifndef TAG_LIBRARY_H
#define TAG_LIBRARY_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
class field{
private:
    int number;
public:
    int getNumber() const;
    void setNumber(int number);
    field( int number);
    field();
    bool operator == (int a);
};

class game{
private:
    field **table=NULL;
    const static int n=4;
    field second [n][n];
    int place_of_zero_x{},place_of_zero_y{};//place of 0
public:
    game();
    ~game();
    friend std::ostream& operator << (std::ostream &out , game &game);
    void create();
    bool wincondition();
    void move(int);
};
#endif //TAG_LIBRARY_H