#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
class Sudoku_Square : public sf::Drawable, public sf::Transformable
{
public:
    int index;
    float size;

    Sudoku_Square();
    Sudoku_Square( int index, float size);
    inline static int selected = -1;

private:
    sf::VertexArray vertices{sf::PrimitiveType::TriangleStrip, 4};    

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};