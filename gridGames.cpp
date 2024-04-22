#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

using namespace std;
int main()
{
    std::cout << "Hello World!\n" << endl;
    sf::RenderWindow window(sf::VideoMode(800, 600), "GridGames!", sf::Style::Default);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);

    sf::Font font;
    if (!font.loadFromFile("resource/arial.ttf"))
    {
        std::cerr << "cannot find font !!" << endl;
    }

    while(window.isOpen())
    {
        sf::Event windowEvent;
        while(window.pollEvent(windowEvent))
        {
            if(windowEvent.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);

        sf::Text content;
        content.setFont(font);
        content.setString("Grid Games");
        content.move(100.f, 200.f);
        content.setCharacterSize(24);
        content.setFillColor(sf::Color::Red);
        content.setStyle(sf::Text::Bold | sf::Text::Underlined);
        
        window.draw(content);
        window.display();
    }
    return 0;
}