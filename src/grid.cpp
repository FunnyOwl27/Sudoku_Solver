#include "grid.h"
#include <string>
#include <iostream>
using std::to_string;

Sudoku_Square::Sudoku_Square()
{
    this->textColor = Color::InputText;
    this->setSize({this->SIZE, this->SIZE});
    this->setOrigin(this->getSize().componentWiseDiv({2, 2})); //    size/2, size/2 set as origin
}

void Sudoku_Square::squareClicked(Sudoku_Square *arr, int index)
{
    if (index >= 82)
    {
        if (SELECTED >=82)
            return;
        arr[SELECTED].setFillColor({25, 25, 25});
        SELECTED = 82;
        return;
    }
    if (index < 0) index += 81;
    if (SELECTED < 82)
    {
        arr[SELECTED].setFillColor(Color::Square);
        arr[SELECTED].textColor = Color::InputText;
    }
    SELECTED = index;
    arr[SELECTED].setFillColor(Color::SelectedSquare);
    arr[SELECTED].textColor = Color::SelectedText;
}

void Sudoku_Square::numberInput(Sudoku_Square* arr,sf::Keyboard::Key a)
{
    if (SELECTED >= 82) return;
    if (a == sf::Keyboard::Key::Backspace || a == sf::Keyboard::Key::Delete) arr[SELECTED].value = 0;

    int num = static_cast<int>(a) - static_cast<int>(sf::Keyboard::Key::Num0);
    if (num > 9 || num < 0) return;
    arr[SELECTED].value = num;
}
void Sudoku_Square::draw(sf::RenderTarget& target, sf::RenderStates states) const 
{
    sf::RenderStates states2 = states;
    sf::VertexArray vertices(sf::PrimitiveType::TriangleStrip, 4);
    for(int i = 0; i < 4; i++)
    {
        vertices[i].position = {i/2 * SIZE, i%2*SIZE};
        vertices[i].color = this->getFillColor();
    }
    states.transform *= this->getTransform();
    target.draw(vertices,states);

    if (value <= 0) return;
    sf::Text text(FONT, to_string(value), SIZE);
    sf::Vector2f offset = {10,-8};

    text.setFillColor(textColor);
    text.setPosition(this->getPosition()- getSize().componentWiseDiv({2,2}) + offset);
    target.draw(text,states2);
}