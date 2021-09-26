#ifndef TAG_LIBRARY_H
#define TAG_LIBRARY_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
class field{
private:
    static int number;
public:
    static void setNumber(int number);
    int getNumber()const;
    field( int number);
    field();
    bool operator == (int a);
};

class game{
private:
    field **table=nullptr;
    const static int n=4;
    field second [n][n];
    int place_of_zero_x{},place_of_zero_y{};//place of 0
public:
    game();
    ~game();
    friend std::ostream& operator << (std::ostream &out , game &game);
    void recursion(int i);
    void create();
    bool wincondition();
    void set_x_y();
    void move();
};
#endif //TAG_LIBRARY_H