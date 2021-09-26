#include "library.h"
int main() {
    srand(time(NULL));
    game tag ;
    tag.create();
    std::cout<<tag;
    tag.set_x_y();
    while (!tag.wincondition()) {
        tag.move();
        std::cout<<tag;
    }
    std::cout<<"you are the champion!)";
    return 0;
}
