#include "library.h"
int main() {
    srand(time(nullptr));
    game *tag = nullptr;
    tag->create();
    std::cout<<tag;
    tag->set_x_y();
    while (!tag->wincondition()) {
        tag->move();
        std::cout<<tag;
    }
    std::cout<<"you are the champion!)";
    delete tag;
    return 0;
}
