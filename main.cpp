#include "include.h"

int main(){
   sf::RenderWindow window(sf::VideoMode(1280, 720), "Gamejam");
   window.setFramerateLimit(60);

   sf::Image WindowIcon;
   WindowIcon.loadFromFile("assets/icon.png");
   window.setIcon(256, 256, WindowIcon.getPixelsPtr());

//    Sprites & Textures
//
   sf::Sprite player;
   sf::Texture tplayer;
   tplayer.loadFromFile("assets/player/player_side.png");
   player.setTexture(tplayer);
   player.setTextureRect(sf::IntRect(0, 64, 64, 64));
   player.setScale(7,7);
   player.setPosition(2440, 5320);
   player.setOrigin(player.getScale().x / 2, player.getScale().y / 2);

   sf::Sprite world1;
   sf::Texture tworld1;
   tworld1.loadFromFile("assets/maps/lvl1/lvl1_1.png");
   world1.setTexture(tworld1);

   sf::Sprite world2;
   sf::Texture tworld2;
   tworld2.loadFromFile("assets/maps/lvl1/lvl1_2.png");
   world2.setTexture(tworld2);

   sf::Sprite world3;
   sf::Texture tworld3;
   tworld3.loadFromFile("assets/maps/lvl1/lvl1_3.png");
   world3.setTexture(tworld3);

   sf::Sprite world4;
   sf::Texture tworld4;
   tworld4.loadFromFile("assets/maps/lvl1/lvl1_4.png");
   world4.setTexture(tworld4);

   sf::Sprite world5;
   sf::Texture tworld5;
   tworld5.loadFromFile("assets/maps/lvl1/lvl1_5.png");
   world5.setTexture(tworld5);

   world1.setScale(6,6);
   world2.setScale(6,6);
   world3.setScale(6,6);
   world4.setScale(6,6);
   world5.setScale(6,6);

   sf::Sprite end;
   sf::Texture tend;
   tend.loadFromFile("assets/icon.png");
   end.setTexture(tend);
   end.setScale(2, 1);
   end.setPosition(2500, 5570);

//    Camera
//
   sf::View camera;

//    Music
//
   sf::Music music;
   if(!music.openFromFile("sfx/spawn.ogg")) { std::cout << "WARNING: Failed to Load Music." << std::endl; }
   music.setLoop(false);
   music.setVolume(100);
   music.play();


   if(!music.openFromFile("theme.ogg")) { std::cout << "WARNING: Failed to Load Music." << std::endl; }
   music.setLoop(true);
   music.play(); 

//    Audio
//
   sf::SoundBuffer buffer;
   sf::Sound sound;
   if(!buffer.loadFromFile("sfx/spawn.ogg"))
      return -1;
   sound.setBuffer(buffer);
   sound.play();


//    Font
//
   sf::Font font;
   if(!font.loadFromFile("assets/font/rainyhearts.ttf")){ std::cout << "ERROR: Couldn't load Font." << std::endl; }

   while(window.isOpen()){

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getPosition().y >= 750 || sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player.getPosition().y >= 750){
         tplayer.loadFromFile("assets/player/player_up.png");
         player.setTextureRect(sf::IntRect(0, 0, 64, 64));
         player.move(0, -10);
         }

      if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player.getPosition().y <= 5460 || sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player.getPosition().y <= 5460){
         tplayer.loadFromFile("assets/player/player_down.png");
         player.setTextureRect(sf::IntRect(0, 0, 64, 64));
         player.move(0, 10);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player.getPosition().x >= 30 || sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player.getPosition().x >= 30){
         tplayer.loadFromFile("assets/player/player_side.png");
         player.setTextureRect(sf::IntRect(0, 0, 64, 64));
         player.move(-10, 0);
      }
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player.getPosition().x <= 4960|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player.getPosition().x <= 4960){
         tplayer.loadFromFile("assets/player/player_side.png");
         player.setTextureRect(sf::IntRect(64, 0, -64, 64));
         player.move(10, 0);
      }

      sf::Event event;
      while(window.pollEvent(event)){
         if(event.type == sf::Event::Closed)
            window.close();
         if(event.type == sf::Event::KeyReleased){
            if(event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up){
               player.setTextureRect(sf::IntRect(0, 64, 64, 64));
            }
            if(event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down){
               player.setTextureRect(sf::IntRect(0, 64, 64, 64));
            }
            if(event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left){
               player.setTextureRect(sf::IntRect(0, 64, 64, 64));
            }
            if(event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right){
               player.setTextureRect(sf::IntRect(64, 64, -64, 64));
            }
         }
      }
      camera.setCenter(player.getPosition().x + 32, player.getPosition().y + 32);
      camera.setSize(window.getSize().x * 1.5, window.getSize().y * 1.5);
      window.clear(sf::Color(114, 117, 27));
      window.setView(camera);
      window.draw(world1);
      window.draw(world2);
      window.draw(world3);
      window.draw(world4);
      window.draw(world5);
      window.draw(player);
      if(player.getPosition().y == 840){
         if(!buffer.loadFromFile("sfx/goal.ogg"))
            return -1;
         sound.setBuffer(buffer);
         sound.play();
         }
      if(player.getPosition().y <= 840){
         sf::Text text("Thank you for playing this demo.", font, 50);
         sf::Text text2("Credits: Art by: szadiart and cainos.", font, 45);
         sf::Text text3("       Music by: antomuto4 [me].", font, 40);
         text.setPosition(2400, 770 - 200);
         text2.setPosition(2400, 770 - 100);
         text3.setPosition(2400, 770);
         window.draw(text);
         window.draw(text2);
         window.draw(text3);
         }
      if(player.getGlobalBounds().intersects(end.getGlobalBounds())){
         sf::Text text("This is a short demo.", font, 50);
         sf::Text text2("Both Collision and Animations do not work.", font, 45);
         sf::Text text3("I made this game in less than 3 hours.", font, 45);
         text.setPosition(player.getPosition().x - 150, player.getPosition().y - 100);
         text2.setPosition(player.getPosition().x - 150, player.getPosition().y - 50);
         text3.setPosition(player.getPosition().x - 150, player.getPosition().y);
         window.draw(text);
         window.draw(text2);
         window.draw(text3);
      }
      if(player.getPosition().y >= 4180){
         sf::Text text("Follow the stone path on your right.", font, 50);
         text.setPosition(1230, 4310);
         window.draw(text);
      }
      window.display();
   }
   return EXIT_SUCCESS;
}
