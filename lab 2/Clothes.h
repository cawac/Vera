#pragma once
#include <iostream>
#include <string>

namespace clothes
{
    class Clothes{
    protected:
        int size{};
        std::string material;
        std::string color;
        bool status=false; // тип надето снято
        bool status_for_the_state_of_the_clothes=false;
        double cost{};
        char sex{};
    public:
        Clothes()=default;

        Clothes(int size, const std::string &material, const std::string &color, double cost, char sex);

        ~Clothes() = default;;

        bool isStatus() const;

        void setStatus(bool status);

        bool isStatusForTheStateOfTheClothes() const;

        void setStatusForTheStateOfTheClothes(bool statusForTheStateOfTheClothes);

        void setCost();

        double getCost() const;

        int getSize() const;

        void setSize(int size);

        const std::string& getMaterial() const;

        void setMaterial(const std::string& material);

        const std::string& getColor() const;

        void setColor(const std::string& color);

        char getSex() const;

        void setSex(char sex);

        void put_on();

        void take_off();

        virtual void unbutton();

        virtual void button();
    };

    class Top : virtual public Clothes
    {
    public:
        static void roll_up_sleeves();
        void pull_up_hood();
    };

    class Bottom : virtual public Clothes
    {
    public:
        void roll_up_pant_leg();
        void put_belt_on();
    };

    class Shirt : private Top
    {
    public:
        void unbutton() override;
        void button() override;
    };

    class Hoodie : protected Top
    {
    public:
        void put_on_a_hood();
        void tie_a_lace();
    };

    class Shorts : public Bottom
    {
    private:
        int length;
    public:
        int getLength() const;
        void setLength(int length);
    };

    class Overalls :public Top, public Bottom
    {

    };

    class Pants : public Bottom
    {
    private:
        int length;
    public:
        int getLength() const;
        void setLength(int length);
    };

    class Dress : public Top, public Bottom
    {
    private:
        int length;
        std::string type;
    public:
        int getLength() const;
        void setLength(int length);
        const std::string &getType() const;
        void setType(const std::string &type);
    };

}
