#include "Game.h"

#include <memory>

//sterowanie:
//strza³ki - ruch
//X otworz skrzynie
//Z get position
//C use item
//I show eq
//J next item in eq

Game::Game()
{
	window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BITS_PER_PIXEL), "Game");
	window->setFramerateLimit(60);

    player = new Player();


    //player = std::make_unique<Player>(); w nag³owku jest kom
	enemy[0] = new Enemy({40,40}, /*{620.f,110.f},*/ 0);
	enemy[1] = new Enemy({70,70}, /*{700.f,300.f},*/ 1);
    
	boundary = new Obstacle();
    ground = new Obstacle({ GROUND_HEIGHT });

    //Platformy - d³ugoœæ musi byæ wielokrotnoœci¹ 10!
	platform[0] = new Obstacle({ 340.f, 430.f}, 160.f);
    platform[1] = new Obstacle({ 100.f,500.f }, 170.f);
    platform[2] = new Obstacle({ 170.f, 370.f }, 100.f);
    platform[3] = new Obstacle({ 60.f, 320.f }, 50.f);
    platform[4] = new Obstacle({ 220.f,280.f }, 800.f);
    platform[5] = new Obstacle({ 1010.f, 500.f }, 170.f);
    platform[6] = new Obstacle({ 870.f, 430.f }, 100.f);
    platform[7] = new Obstacle({ 1040.f,370.f }, 140.f);
    platform[8] = new Obstacle({ 1020.f, 190.f}, 210.f);
    platform[9] = new Obstacle({ 850.f, 130.f},100.f);
    platform[10] = new Obstacle({1000.f, 80.f }, 170.f);
    platform[11] = new Obstacle({420.f, 100.f }, 370.f);
    platform[12] = new Obstacle({100.f, 80.f}, 140.f);
    platform[13] = new Obstacle({1180.f, 80.f }, 180.f);
    
    //std array albo std vector
    
    //Coin
    coin[0] = new Coin(/*{300.f, 300.f}*/);
    coin[1] = new Coin(/*{ 400.f, 200.f }*/);

    //Booster
    booster = new Booster(1);
    destroyer = new Booster(2);
    slower = new Booster(3);
    friendly = new Booster(4);
    helper = new Booster(5);
    shot = new Booster(6);
    
 
    //score
    scoreVis = new Score();

    //background
    background = new Background();

    //interactive - doors, chests
    chest[0] = new Chest({ 200.f, 600.f-45.f}, 0);

    //items
    //item[0] = new Item("heal", 1);
    //item[1] = new Item("heal", 2);
    //item[2] = new Item("heal", 3);
    //item[3] = new Item("mana", 1);
    //item[4] = new Item("mana", 2);
    //item[5] = new Item("mana", 3);
    //for (int i = 6; i < 11; i++)
    //{
    //    item[i] = new Item("speed", i - 6);
    //}

	for (int i = 0;i<NUMBER_OF_HP_POTIONS;i++)
    {
        potionHP[i] = new PotionHP(sf::Vector2f(280.f+i*40.f, 240.f));
    }

	for (int i = 0;i<2;i++)
    {
        potionMP[i] = new PotionMP(sf::Vector2f(500.f+i*40.f, 240.f));
    }
   

    //inventory
    inventory = new Inventory();


}




void Game::Loop()
{
    sf::Event event;
    const float fallSpeed = -5.5f;
  
   
    //sf::Clock FPS;
    //float lastTimeFPS = 0.f;

    while (window->isOpen())
    {
        //
        //float currentTimeFPS = FPS.restart().asSeconds();
        //float fps = 1.f / currentTimeFPS ;
        //lastTimeFPS = currentTimeFPS;
        //std::cout <<"FPS: " << fps << '\n';

        //player
        //player->movementPlayer();
        for (int i = 0; i < NUMBER_OF_PLATFORMS; i++)
        {
            player->collisionWithObstacle(platform[i]);
        }
       
        player->collisionWithObstacle(ground);
        player->jump();
        player->gravity(ground);
        player->checkCollisionLeft();
        //player->useItem(scoreVis, event);
        //boosters spawn
        booster->spawnBooster();
        destroyer->spawnDestroyer();
        slower->spawnSlower();
        friendly->spawnFriendly();

        //for (int i = 0; i<NUMBER_OF_HP_POTIONS;i++)
        //{
        //    potionHP[i]->collectItem(potionHP[i]->getShapePtr(), player, inventory);//TODO ?
        //}
        //for (int i = 0; i<NUMBER_OF_MP_POTIONS;i++)
        //{
        //    potionMP[i]->collectItem(potionMP[i]->getShapePtr(), player, inventory);//TODO ?
        //}
        for (int i = 0; i<NUMBER_OF_HP_POTIONS;i++)
        {
            potionHP[i]->addItem(player, inventory);//TODO ?
        }
        for (int i = 0; i<NUMBER_OF_MP_POTIONS;i++)
        {
            potionMP[i]->addItem( player, inventory);//TODO ?
        }

        //boosters functions
        //acceleration
        booster->accel(player);//tutaj jest movement player, nie jestem z tego dumny

        //destroyer
        for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
        {
            destroyer->destroy(player,enemy[i], scoreVis);
        }

        //slower     
        for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
        {
            slower->slow(player, enemy[i]);
        }

        //helper
        for (int i = 0; i<NUMBER_OF_ENEMIES;i++)
        {
            friendly->friendShots(player, enemy[i], helper, shot, scoreVis);
        }

        //item 
        //for (int i = 0; i<NUMBER_OF_ITEMS;i++)
        //{
        //    item[i]->spawnItem(chest[0], 0);
        //    item[i]->grabItem(player, scoreVis, inventory);
        //}
        

        while (window->pollEvent(event))
        {


            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window->close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                player->getPos();

            //player events
            player->useItem( scoreVis, scoreVis, inventory, event);
            
            //inventory events
            inventory->showInv(event);
            inventory->selectItem(event);

        }


        for (int i = 0; i < NUMBER_OF_ENEMIES; i++)
        {
            if (player->getShape().getGlobalBounds().intersects(enemy[i]->getShape(i).getGlobalBounds()))
            {
                player->teleport();
                scoreVis->getDeath();
            }
        }


        //coin logic
        for (int i = 0; i < 2; i++)
        {
            if (player->getShape().getGlobalBounds().intersects(coin[i]->getShape().getGlobalBounds()))
            {
                coin[i]->teleportCoin();
                scoreVis->getScore();
            }
        }
        
        for (int i = 0; i < NUMBER_OF_COINS; i++)
        {
           coin[i]->setCoinTexture();
           coin[i]->moveCoin(i);
        }
        //player->glowPlayer();
        
        //chest logic
        chest[0]->action(player, 0);
        
        //window display
        window->clear();
         background->drawTo(*window);//zawsze na pocz¹tku ma siê renderowaæ! musi byæ "pod spodem"

        for (int i = 0; i <= 1; i++)
            enemy[i]->drawEnemy(*window, i);

        for (int i = 0; i < NUMBER_OF_PLATFORMS; i++)
            platform[i]->drawObstacle(*window);
      
        for (int i = 0; i <= 1; i++)
            coin[i]->drawCoin(*window);


      
        scoreVis->drawScore(*window);
        ground->drawObstacle(*window);
        boundary->drawBoundary(*window);

        booster->drawBooster(*window);
        destroyer->drawBooster(*window);
        slower->drawBooster(*window);
        friendly->drawBooster(*window);
        helper->drawBooster(*window);

        shot->drawBooster(*window);

        chest[0]->drawChest(*window, 0);
        //for (int i = 0; i<NUMBER_OF_ITEMS; i++)
        //{
        //    item[i]->drawItem(*window);
        //}

        for (int i = 0; i<NUMBER_OF_HP_POTIONS;i++)
        {
            potionHP[i]->drawItem(*window, potionHP[i]->getShape());
        }
        for (int i = 0; i<NUMBER_OF_MP_POTIONS;i++)
        {
            potionMP[i]->drawItem(*window, potionMP[i]->getShape());
        }

        player->drawTo(*window);
        inventory->drawInv(*window);


        window->display();
    }
}