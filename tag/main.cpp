#include "library.h"
int main() {
    srand(time(NULL));
    game tag ;
    int changefield;
    tag.create();
    std::cout<<tag;
    tag.set_x_y();
    while (!tag.wincondition()) {
        std::cin>>changefield;
        tag.move(changefield);
        std::cout<<tag;
    }
    std::cout<<"you are the champion!)";
    return 0;
}
