#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <array>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
class Sudoku_Square : public sf::RectangleShape
{
public:
    static float SIZE;
    static sf::Font FONT;
    int value = 0;
    sf::Color textColor;
    Sudoku_Square();
    inline static int SELECTED = 82;
    static void squareClicked(Sudoku_Square* arr, int index);
    static void numberInput(Sudoku_Square* arr, sf::Keyboard::Key number);
    static std::array<int, 81> sudokuToArray(Sudoku_Square* arr);
    class Color
    { 
    public: 
        static constexpr sf::Color Background = {70, 70, 70};
        static constexpr sf::Color InputText = {245, 245, 255};
        static constexpr sf::Color Square = {25, 25, 25};
        static constexpr sf::Color SolvedText = {3, 252, 140};
        static constexpr sf::Color SelectedSquare = {70,70,70};
        static constexpr sf::Color SelectedText = {3, 161, 252};
    };
private: 
    sf::VertexArray m_vertices;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
    
};