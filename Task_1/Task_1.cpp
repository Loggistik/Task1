#include <iostream>

class Vector {
public:

    Vector() 
    {
        x = 0;
        y = 0;
        z = 0;
    }

    Vector(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    operator float() 
    {
        return sqrt(x * x + y * y + z * z);
    }

    float operator[](int index)
    {
        switch (index)
        {
        case 0:
            return x;
            break;

        case 1:
            return y;
            break;

        case 2:
            return z;
            break;

        default:
            return 0;
            break;
        }
    }

    friend Vector operator+(const Vector& a, const Vector& b);
    friend std::ostream& operator<<(std::ostream& out, const Vector& v);
    friend Vector operator*(const Vector& a, const float& b);
    friend Vector operator-(const Vector& a, const Vector& b);
    friend std::istream& operator>>(std::istream& in, Vector& v);

private:
    float x;
    float y;
    float z;
};

Vector operator+(const Vector& a, const Vector& b)
{
    return Vector(a.x + b.x, a.y + b.y, a.z + b.z);
}

std::ostream& operator<<(std::ostream& out, const Vector& v)
{
    out << ' ' << v.x << " " << v.y << " " << v.z;
    return out;
}

Vector operator*(const Vector& a, const float& b)
{
    return Vector(a.x * b, a.y * b, a.z * b);
}

Vector operator-(const Vector& a, const Vector& b) 
{
    return Vector(a.x - b.x, a.y - b.y, a.z - b.z);
}

std::istream& operator>>(std::istream& in, Vector& v) 
{
    in >> v.x >> v.y >> v.z;
    return in;
}

int main()
{
    Vector v1 = Vector(1, 1, 1);
    Vector v2 = v1 * 2.0f;

    std::cout << "v1:" << v1 << "\n";
    std::cout << "v2:" << v2 << "\n";
    std::cout << v2 - v1 << "\n";
    std::cin >> v2;
    std::cout << "v:" << v2;

}

