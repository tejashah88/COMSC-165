#ifndef CIRCLE_H
#define CIRCLE_H

const float PI = 3.14159f;

class Circle {
    public:
        float getRadius() const { return radius; }
        void setRadius(float val) { radius = val; }
        float getArea() const { return radius * radius * PI; }

    private:
        float radius;
};

#endif // CIRCLE_H
