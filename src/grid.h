#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Sudoku_Square : public sf::Drawable, public sf::Transformable
{
public:
    Sudoku_Square();
    Sudoku_Square(sf::Vector2f position, int index, double size);
    inline static int selected = -1;

private:
    sf::VertexArray vertices{sf::PrimitiveType::TriangleStrip, 4};
    sf::Vector2f position;
    int index;
    float size;
    

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};