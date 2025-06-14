#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
class Sudoku_Square : public sf::RectangleShape
{
public:
    //int index;
    static float SIZE;
    Sudoku_Square();
    Sudoku_Square(sf::Vector2f size);
    Sudoku_Square(sf::Vector2f size, int index);
    inline static int SELECTED = -1;

private:    
};