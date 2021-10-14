#include <SFML/Graphics.hpp>
#include "HeaderAROLF.h"
#include <iostream>
#include <windows.h>
#include <sstream>
using namespace sf;

void rnd() {

    if (xE < 1920) {
        xE = rand() % 1650;
        yE = rand() % 980;
        
        //Sleep(1000);
    }
  
}
void rnd1() {

    if (xE < 1920) {
        xE1 = rand() % 1750;
        yE1 = rand() % 1080;

    
    }

}

void rnd2() {

    if (xE < 1920) {
        xE2 = rand() % 1750;
        yE2 = rand() % 1080;

       
    }

}

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "AROLF");

    Font font;//шрифт 
    font.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\ARIAL.ttf");
    Text text("", font, 20);
    Texture arolfTexture;
    arolfTexture.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\aRolf.png");
    Sprite arolfSprite(arolfTexture, IntRect(0, 0, 110, 110));
    arolfSprite.scale(0.7, 0.7);
    
  
    Texture enemyTexture;
    enemyTexture.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\Starege.png");
    Sprite enemySprite(enemyTexture, IntRect(0, 0, 110, 110));
    enemySprite.scale(0.5, 0.5);
    enemySprite.setPosition(0, 0);
   
    Texture enemyTexture1;
    enemyTexture1.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\MMMM.png");
    Sprite enemySprite1(enemyTexture1, IntRect(0, 0, 110, 110));
    enemySprite1.scale(0.5, 0.5);
    enemySprite.setPosition(0, 0);

    Texture enemyTexture2;
    enemyTexture2.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\strgM.png");
    Sprite enemySprite2(enemyTexture2, IntRect(0, 0, 110, 110));
    enemySprite2.scale(0.5, 0.5);
    enemySprite.setPosition(0, 0);

    srand(time(NULL));

    Transform transform;
    rnd();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Перемещение арольфа

        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            x -= speed;
            std::cout << x << " " << y << std::endl;
        } 

        if (Keyboard::isKeyPressed(Keyboard::W))
        {
            y -= speed;
            std::cout << x << " " << y << std::endl;
        }

        if (Keyboard::isKeyPressed(Keyboard::S))
        {

            y += speed;
            std::cout << x << " " << y << std::endl;
        }

        if (Keyboard::isKeyPressed(Keyboard::D))
        {
            x += speed;

            std::cout << x << " " << y << std::endl;
        }

       //арольф ест старыгу
        if (arolfSprite.getGlobalBounds().intersects(enemySprite.getGlobalBounds())) {
            rnd();
            pointer++;
        }
        if (arolfSprite.getGlobalBounds().intersects(enemySprite1.getGlobalBounds())) {
            rnd1();
            pointer++;
        }
        if (arolfSprite.getGlobalBounds().intersects(enemySprite2.getGlobalBounds())) {
            rnd2();  
            pointer++;
        }
        std::cout << pointer << " " << std::endl;
        
        std::ostringstream playerScoreString;    // объявил переменную
        playerScoreString << pointer;		//занес в нее число очков
        text.setString("emote picked: " + playerScoreString.str()); //задает строку тексту
        text.setPosition(1700, 100);
        

        //Перемещение арольфа с телепортами 
        if (y < 0) y = 1080;
        if (x < 0) x = 1920;
        if (y > 1080) y = 0;
        if (x > 1920)x = 0;


        arolfSprite.setPosition(x, y);
        enemySprite.setPosition(xE, yE);
        enemySprite1.setPosition(xE1, yE1);
        enemySprite2.setPosition(xE2, yE2);

        window.clear();
        window.draw(text);
        window.draw(arolfSprite);
        window.draw(enemySprite);
        window.draw(enemySprite1);
        window.draw(enemySprite2);
        window.display();
    }
    
    return 0;
}
    
