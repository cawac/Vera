//
// Created by alex on 08/11/2021.
//
#include "Clothes.h"

void clothes::Clothes::take_off() {
    if(status_for_the_state_of_the_clothes) {
        status_for_the_state_of_the_clothes=false;
        std::cout << "clothes been take off\n";
    }
    else
        std::cout<<"clothes been already take off\n";
}

int clothes::Clothes::getSize() const {
    return size;
}

void clothes::Clothes::setSize(int size) {
    Clothes::size = size;
}

const std::string &clothes::Clothes::getMaterial() const {
    return material;
}

void clothes::Clothes::setMaterial(const std::string &material) {
    Clothes::material = material;
}

const std::string &clothes::Clothes::getColor() const {
    return color;
}

void clothes::Clothes::setColor(const std::string &color) {
    Clothes::color = color;
}

bool clothes::Clothes::isStatus() const {
    return status;
}

void clothes::Clothes::put_on() {
    if(!status_for_the_state_of_the_clothes) {
        status_for_the_state_of_the_clothes=true;
        std::cout << "clothes been put on\n";
    }
    else
        std::cout<<"clothes been already put on\n";
}

void clothes::Clothes::setCost() {

}

double clothes::Clothes::getCost() const {
    return cost;
}

char clothes::Clothes::getSex() const {
    return sex;
}

void clothes::Clothes::setSex(char sex) {
    Clothes::sex = sex;
}

void clothes::Clothes::button() {
    if (!status)
    {
        status=true;
        std::cout<<"close\n";
    }
    else
        std::cout<<"have already been closed\n";
}

void clothes::Clothes::unbutton() {
    if (status)
    {
        status=false;
        std::cout<<"open\n";
    }
    else
        std::cout<<"have already been opened\n";
}

void clothes::Clothes::setStatus(bool status) {
    Clothes::status = status;
}

bool clothes::Clothes::isStatusForTheStateOfTheClothes() const {
    return status_for_the_state_of_the_clothes;
}

void clothes::Clothes::setStatusForTheStateOfTheClothes(bool statusForTheStateOfTheClothes) {
    status_for_the_state_of_the_clothes = statusForTheStateOfTheClothes;
}

clothes::Clothes::Clothes
(int size, const std::string &material, const std::string &color, double cost, char sex) : size(size), material(material),
 color(color), cost(cost), sex(sex) {}

void clothes::Top::pull_up_hood() {

}

void clothes::Top::roll_up_sleeves(){
    std::cout<<"Sleeves are rolled up\n";

}

void clothes::Bottom::roll_up_pant_leg() {

}

void clothes::Bottom::put_belt_on() {

}

void clothes::Shirt::button() {
    if (!status)
    {
        status=true;
        std::cout<<"buttons on shirt close\n";
    }
    else
        std::cout<<"buttons on shirt have already been closed\n";
}

void clothes::Shirt::unbutton() {
    if (status)
    {
        status=false;
        std::cout<<"buttons on shirt open\n";
    }
    else
        std::cout<<"buttons on shirt have already been opened\n";
}

void clothes::Hoodie::put_on_a_hood() {
    std::cout<<"Hood is putted on\n";
}

void clothes::Hoodie::tie_a_lace() {
    std::cout<<"Lace of hoodie is tied\n";
}

int clothes::Dress::getLength() const {
    std::cout<<"Length of dress is"<<length<<"\n";
    return length;
}

void clothes::Dress::setLength(int length) {
    Dress::length = length;
}

const std::string &clothes::Dress::getType() const {
    std::cout<<"Type of dress is"<<type<<"\n";
    return type;
}

void clothes::Dress::setType(const std::string &type) {
    Dress::type = type;
}

int clothes::Pants::getLength() const {
    return length;
}

void clothes::Pants::setLength(int length) {
    Pants::length = length;
}

int clothes::Shorts::getLength() const {
    return length;
}

void clothes::Shorts::setLength(int length) {
    Shorts::length = length;
}