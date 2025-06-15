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
    inline static int SELECTED = 82;
    static void squareClicked(Sudoku_Square* arr,int index);
private:    
};