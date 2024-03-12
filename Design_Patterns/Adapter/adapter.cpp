#include <iostream>

struct Square
{
  int side{ 0 };

  Square(const int side)
    : side(side) {}
};

struct Rectangle
{
  virtual int width() const = 0;
  virtual int height() const = 0;

  int area() const
  {
    return width() * height();
  }
};

struct SquareToRectangleAdapter : Rectangle
{
private:
  const Square& square;

public:
  SquareToRectangleAdapter(const Square& square)
    : square(square) {}

  int width() const override
  {
    return square.side;
  }

  int height() const override
  {
    return square.side;
  }
};

int main() {
    Square square(5);
    SquareToRectangleAdapter adapter(square);

    std::cout << "Area of adapted rectangle: " << adapter.area() << std::endl;

    return 0;
}
