#include "Inventory.h"

Inventory::Inventory()
{
	sf::Vector2f inventorySize{200.f, 350.f};
	sf::Vector2f inventoryPosition{200.f, 350.f};

	inventoryBackground.setSize(inventorySize);
	inventoryBackground.setFillColor(sf::Color::Blue);
	inventoryBackground.setOrigin(inventorySize.x, 0.f);
	inventoryBackground.setPosition(WINDOW_WIDTH, 0.f);

	arial.loadFromFile("arial.ttf");

	showedInventory << "Inventory";
	invVis.setFont(arial);
	invVis.setPosition(inventoryBackground.getPosition().x - inventoryBackground.getOrigin().x, 0.f);
	invVis.setCharacterSize(25);
	invVis.setString(showedInventory.str());
}

void Inventory::drawInv(sf::RenderWindow& window)
{
	if (switchInv)
	{
		window.draw(inventoryBackground);
		window.draw(invVis);
		for (int i = 0; i<itemAmount;i++)
		{
			//showedItem[i].str("");
			window.draw(itemVis[i]);
		}
	}
}

void Inventory::showInv(sf::Event& event)
{
	if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::I)
	{
		switchInv = !switchInv;
		//std::cout << "showInv dziala" << '\n';
	}
}

Inventory::~Inventory()
{

}

void Inventory::contains()
{

}

bool Inventory::isItemNameUnique(/*std::string itemUniqueness[maxItemAmount], */int itemNumber)
{
	//std::cout << "isitemNameUnique itemNUmber: " << itemNumber << '\n';
	for (int i = 0; i < itemNumber; i++)
	{
		std::cout << "showedItem["<<itemNumber<<"]: " << showedItem[itemNumber].str() << " = "<< "showedItem["<<i<<"]: " << showedItem[i].str() << '\n';

		if (showedItem[itemNumber].str() == showedItem[i].str() && itemNumber >0)
		{
			return false;
		}

	}
	return true;
}

void Inventory::addItem(std::string itemName)
{
	itemAmount++;
	arial.loadFromFile("arial.ttf");
	for (int i = itemAmount - 1; i < itemAmount; i++)
	{
		//std::cout << "Inventory::addItem itemAmount: " << itemAmount << '\n';

		showedItem[i] << itemName /*<<" x"<< itemCount*/ << '\n';
		if (isItemNameUnique(itemAmount-1) == false)
		{
			std::cout << "isItemNameUnique false" << '\n';			
		}
		else 
		{
			std::cout << "isItemNameUnique true" << '\n';
			//showedItem[i] << itemName <<'\n';
			itemSlot++;
			itemVis[i].setFont(arial);
			itemVis[i].setPosition(invVis.getPosition().x, (itemSlot)*itemPositionInInventory);
			itemVis[i].setCharacterSize(25);
			itemVis[i].setString(showedItem[i].str());
		}
		
	}
}

void Inventory::deleteItem()
{
	itemAmount--;
	if (itemSlot != 0)
	{
		itemSlot--;
	}
	arial.loadFromFile("arial.ttf");
	showedItem[itemAmount].str("");//dzia³a doraŸnie, bo nie mamy rozró¿nienia itemów póki co
	//for (int i = itemAmount; i == i-1; i--)
	//{
	//	showedItem[i].str("");
	//}
}