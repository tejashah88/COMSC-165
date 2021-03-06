#ifndef SQUARE_H
#define SQUARE_H

const float PI = 3.14159f;

class Square {

    public:
        Square() : side(1) {};
        Square(int s) : side(s) {};
        ~Square() { };

        void setSide(float length);
        float findArea();
        float findPerimeter();

    private:
        float side;
};

#endif // SQUARE_H
