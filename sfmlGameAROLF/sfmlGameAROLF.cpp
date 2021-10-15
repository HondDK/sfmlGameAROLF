#include <SFML/Graphics.hpp>
#include "HeaderAROLF.h"
#include <iostream>
#include <windows.h>
#include <sstream>
#include <SFML/Audio/Music.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

using namespace sf;

void rnd() {

    if (xE < 1920) {
        xE = rand() % 1650;
        yE = rand() % 980;
    }
    if (pointer > 30) {
        xD = rand() % 1600;
        yD = rand() % 900;


    }
    //Sleep(1000);
}
void rnd1() {

    if (xE < 1920) {
        xE1 = rand() % 1550;
        yE1 = rand() % 900;
        if (pointer > 30) {
            xD = rand() % 1600;
            yD = rand() % 900;

            
        }
    }

}

void rnd2() {

    if (xE < 1920) {
        xE2 = rand() % 1750;
        yE2 = rand() % 990;
        if (pointer > 30) {
            xD = rand() % 1600;
            yD = rand() % 900;
        }
        
    }
}

int main()
{
    RenderWindow window(sf::VideoMode(1920, 1080), "AROLF");

    Font font;//шрифт 
    font.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\ARIAL.ttf");
    Text text("", font, 20);


    // Музыка и звуки
    Music music;
    music.openFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\wave.wav");
    music.play();
    
   /*
    Music hard;
    hard.openFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\newtopsandteesspace_Mick_Gordon_-_Rip_Tear_48126019.ogg");
    hard.play(); 
    */

    SoundBuffer eatBuffer;
    eatBuffer.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\inecraft_pick_u.ogg");
    Sound eat;
    eat.setBuffer(eatBuffer);

    SoundBuffer damageBuffer;
    damageBuffer.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\inecraft_hurt_sound.ogg");
    Sound damage;
    damage.setBuffer(damageBuffer);

    //фон
    Texture fon2Texture;
    fon2Texture.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\fon2.jpg");
    Sprite fonSprite(fon2Texture);


   // Персонаж
    Texture arolfTexture;
    arolfTexture.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\aRolf.png");
    Sprite arolfSprite(arolfTexture, IntRect(0, 0, 110, 110));

    arolfSprite.scale(0.7, 0.7);
    if (pointer > 20)  arolfSprite.scale(1, 1);
    if (pointer > 40)  arolfSprite.scale(1.5, 1.5);
    if (pointer > 60)  arolfSprite.scale(2, 2);
    if (pointer > 80)  arolfSprite.scale(3, 3);
    if (pointer > 100)  arolfSprite.scale(4, 4);
    if (pointer > 120)  arolfSprite.scale(5, 5);
    if (pointer > 120)  arolfSprite.scale(6, 6);

    // Клон
   // Sprite arolfSprite1(arolfTexture, IntRect(0, 0, 110, 110));
   // arolfSprite1.scale(0.7, 0.7);
  
    Texture LOVE;
    LOVE.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\pepoLOVE.png");
    Sprite LOVESPRITE(LOVE, IntRect(0, 0, 110, 110));
    LOVESPRITE.scale(0.5, 0.5);
    LOVESPRITE.setPosition(0, 0);

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

    //OMEGALUL
    Texture damageTexture;
    damageTexture.loadFromFile("C:\\Users\\Danil\\Desktop\\sfmlGameAROLF\\mode\\MEGALUL.png");
    Sprite damageSprite(damageTexture, IntRect(0, 0, 130, 120));
    damageSprite.scale(1, 1);
    damageSprite.setPosition(0, 0);


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
            if (heal == 0) window.close();
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
        /*
        // Перемещение арольфа клона

        if (Keyboard::isKeyPressed(Keyboard::J))
        {
            xA -= speed;
            std::cout << x << " " << y << std::endl;
        }

        if (Keyboard::isKeyPressed(Keyboard::I))
        {
            yA -= speed;
            std::cout << x << " " << y << std::endl;
        }

        if (Keyboard::isKeyPressed(Keyboard::K))
        {

            yA += speed;
            std::cout << x << " " << y << std::endl;
        }

        if (Keyboard::isKeyPressed(Keyboard::L))
        {
            xA += speed;
            std::cout << x << " " << y << std::endl;
        }
        */

        // увеличение скорости
        if (pointer > 25) speed += 0.000001;


       //арольф ест старыгу
        if (arolfSprite.getGlobalBounds().intersects(enemySprite.getGlobalBounds())) {
            rnd();
            eat.play();
            pointer++;
        }
        if (arolfSprite.getGlobalBounds().intersects(enemySprite1.getGlobalBounds()) ) {
            rnd1();
            eat.play();
            pointer++;
        }
        if (arolfSprite.getGlobalBounds().intersects(enemySprite2.getGlobalBounds())) {
            rnd2();
            eat.play();
            pointer++;
        }
        // OMEGALUL киллер
        if (arolfSprite.getGlobalBounds().intersects(damageSprite.getGlobalBounds())) {
            rnd();
            damage.play();
            heal -= 1;
        }

        /*
        // pepoLOVE
        if ((arolfSprite.getGlobalBounds().intersects(LOVESPRITE.getGlobalBounds()))) {
            rndLOVE();
            heal++;
       }
        */

       

        //std::cout << pointer << " " << std::endl;

        std::ostringstream Heal;
        Heal << heal;
        std::ostringstream playerScoreString;    
        playerScoreString << pointer;		
        text.setString("emote picked:   "  +playerScoreString.str() +  "\nHP: " + Heal.str()); 
        text.setPosition(1700, 100);
        
        
        //Перемещение арольфа с телепортами 
        if (y < 0) y = 1080;
        if (x < 0) x = 1920;
        if (y > 1080) y = 0;
        if (x > 1920)x = 0;
        /*
        if (yA < 0) yA = 1080;
        if (xA < 0) xA = 1920;
        if (yA > 1080) yA = 0;
        if (xA > 1920)xA = 0;
        */
       
        arolfSprite.setPosition(x, y);
        //if (pointer >= 25) arolfSprite1.setPosition(xA, yA);
        enemySprite.setPosition(xE, yE);
        enemySprite1.setPosition(xE1, yE1);
        enemySprite2.setPosition(xE2, yE2);
        damageSprite.setPosition(xD, yD);
       // LOVESPRITE.setPosition(xL, yL);
        fonSprite.setPosition(0, 0);

        window.clear();
        window.draw(fonSprite);
        window.draw(text);
        window.draw(arolfSprite);
        //if (pointer >= 25) window.draw(arolfSprite1);
        
        //window.draw(LOVESPRITE);
        window.draw(enemySprite);
        window.draw(enemySprite1);
        window.draw(enemySprite2);
      
        if (pointer >= 30) window.draw(damageSprite);
        window.display();

       
    }
    
    return 0;
}
    
