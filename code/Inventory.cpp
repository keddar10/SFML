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
	invVis.setCharacterSize(characterSize);
	invVis.setString(showedInventory.str());

	sf::Vector2f indexSize{ 10.f, 10.f };
	sf::Vector2f indexPosition{inventoryBackground.getPosition().x - inventoryBackground.getSize().x - 15.f, 30.f+(1.5f * indexSize.y)};

	inventoryIndex.setSize(indexSize);
	inventoryIndex.setFillColor(sf::Color::Red);
	inventoryIndex.setOrigin(indexSize.x / 2, indexSize.y /2);
	inventoryIndex.setPosition(indexPosition);
}

void Inventory::drawInv(sf::RenderWindow& window)
{
	if (switchInv)
	{
		inventoryIndex.rotate(5);
		window.draw(inventoryBackground);
		window.draw(inventoryIndex);
		window.draw(invVis);
		for (int i = 0; i<itemAmount;i++)
		{
			//showedItem[i].str("");
			window.draw(itemVis[i]);
			window.draw(counterVis[i]);
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
		//std::cout << "showedItem["<<itemNumber<<"]: " << showedItem[itemNumber].str() << " = "<< "showedItem["<<i<<"]: " << showedItem[i].str() << '\n';

		if (showedItem[itemNumber].str() == showedItem[i].str() && itemNumber >0)
		{
		//	std::cout << "NOT UNIQUE" << '\n';//OK
			return false;
		}

	}
	return true;
}

void Inventory::addItemToInventory(std::string itemName)
{
	//itemAmount++;
	arial.loadFromFile("arial.ttf");

	showedItem[itemAmount].str("");
	showedItem[itemAmount] << itemName;

	
	if (isItemNameUnique(itemAmount) == false)
	{
		//std::cout << "isItemNameUnique false" << '\n';
		
		showedCounter[getItemSlot(itemName) - 1].str("");//zerowanie stringa
		showedCounter[getItemSlot(itemName)-1] <<"x"<< increaseItemCount(itemName);
		counterVis[getItemSlot(itemName)-1].setFont(arial);
		counterVis[getItemSlot(itemName)-1].setPosition(static_cast<float>(WINDOW_WIDTH-characterSize-7), static_cast<float>(getItemSlot(itemName)*itemPositionInInventory));//OK
		counterVis[getItemSlot(itemName)-1].setCharacterSize(characterSize);
		counterVis[getItemSlot(itemName)-1].setString(showedCounter[getItemSlot(itemName)-1].str());

	}
	else
	{
		increaseItemCount(itemName);
		itemCount[itemSlot]++;//tylko zeby ilosc wyswietlana sie zgadzala
		itemSlot++;
		itemVis[itemAmount].setFont(arial);
		itemVis[itemAmount].setPosition(invVis.getPosition().x, static_cast<float>((itemSlot)*itemPositionInInventory));
		itemVis[itemAmount].setCharacterSize(characterSize);
		itemVis[itemAmount].setString(showedItem[itemAmount].str());
		setItemSlot(itemName, itemSlot);
		
		itemAmount++;
	}
}



void Inventory::setItemSlot(std::string itemNameset, int positionInEq)
{
	strVec.push_back(itemNameset);
	intVec.push_back(positionInEq);//tutaj przekazuje itemSlot
	//moze przekaze tutaj inreaseItemCount? 
	//std::cout << "Inventory::setItemSlot NAME= " << itemNameset << " POSITION = " << positionInEq << '\n';
}

unsigned int Inventory::getItemSlot(std::string itemNameget)
{
	std::vector<int>::size_type sizeOfVector = strVec.size();
	
	for (unsigned int i = 0; i < sizeOfVector; i++)
	{
		if (itemNameget == strVec[i])//TODO xd
		{
			return i+1;
			break;
		}
	}
	return 0;
}
unsigned int Inventory::getItemSlot(int counter)
{
	//std::cout << "getItemSlot int counter: " << intVec[counter] << '\n';
	return intVec[counter];
}

void Inventory::substractItemAmount(int itemAmountArray)
{
	if (itemAmountArray == 0 && itemAmount != 0)
	{
		//std::rotate? je�li itemAmount spada mi do 0 to przerzucam item na koniec i go usuwam przez pop_back, to ni�ej oddzielone tabem 
		uint8_t offset = itemSelector - 1;
		std::rotate(intVec.begin() + offset, intVec.begin() + itemSelector, intVec.end());//przerzuca aktualny item na sam koniec wektora jako indeks
		intVec.pop_back();//tu usuwa ten item jako indeks
		std::rotate(strVec.begin() + offset, strVec.begin() + itemSelector, strVec.end());//item na koneic wektora jako nazwa
		strVec.pop_back();//usuwa item jako nazwe
		//TODO jak zbiore HP a potem MP, ale najpierw zjem HP, to:
		//1. widze HP mimo wszystko w inventory - nie podmienia si�, zjadam item po lokalizacji czy co�?
		//2. intVec dla MP ma wartosc 2, a powinien chyba 1?
		//3. co� jeszcze na pewno jest �le xD
		itemAmount--;
		itemSlot--;
		std::cout << "Inventory::substractItemAmount itemAmount = " << itemAmount << '\n';//jaki� switch item�w? pushback co� takiego?
	}
}

void Inventory::deleteItem()//TODO naprawic delete item xd + wybra� ktory item uzywam 
{
	//TODO itemCount i strVec nie dziala w taki sam spos�b
	//TODO na nowo podjac sie usuwania/uzywania itemow
	//resetItemSelector();
	//musze przekaza� tutaj dok�adnie kt�ry item zu�ywam! a nie w zale�no�ci od itemSelector! tzn w zale�no�ci od niego, ale inaczej xD
	if (switchInv  && itemCount[itemSelector - 1] > 0)
	{
		std::cout << '\n';
		std::cout << "deleteItem()intVec: item used int: " << intVec[itemSelector -1 ] << '\n';
		std::cout << "deleteItem()strVec: item used string: " << strVec[itemSelector -1  ] << '\n';
		itemCount[itemSelector-1]--;
		substractItemAmount(itemCount[itemSelector - 1]);
		std::cout << "deleteItem(): itemCount[i]after subtraction: " << itemCount[itemSelector - 1] << "\n\n";
	}
	else
	{
		std::cout << "brak itemu" << '\n';
	}
}

void Inventory::resetItemSelector()
{
	if (itemSelector > itemSlot)
	{
		itemSelector = 1;
	}
}

void Inventory::selectItem(sf::Event& eventCalled)
{
	resetItemSelector();
	if (switchInv && eventCalled.type == sf::Event::KeyReleased && eventCalled.key.code == sf::Keyboard::J && itemSlot != 0)
	{
		for (int i = 0; i<itemAmount;i++)//tylko do kontroli
		{
			std::cout << "intVec["<<i<<"]: " << intVec[i]<<'\n';
			std::cout << "strVec["<<i<<"]: " << strVec[i]<<'\n';
		}
		std::cout << "selectItem(): " << itemSelector<<'\n';
		std::cout << "selectItem()intVec: selected item int:" << intVec[itemSelector-1] << '\n';
		std::cout << "selectItem()strVec: selected item str:" << strVec[itemSelector-1] << '\n';
		std::cout << "selectItem(): selected item itemCount:" << itemCount[itemSelector-1] << '\n';//nie itemCount, bo itemCount przechowuje STA�E po�o�enia element�w, MP zawsze jest [1], 
		//a jak zbior� go pierwszego to wy�wietlam tutaj itemCoumt [0], bo itemSelector = 1 
		
		inventoryIndex.setPosition(inventoryIndex.getPosition().x, static_cast<float>(/*getItemSlot(itemSelector) **/((itemSelector+1) * itemPositionInInventory)-characterSize/2));
		//getItemSlot(0);
		
		itemSelector++;
	}	
}

std::string Inventory::getItemCountInString(int i)//zamiana itemCount na string
{
	std::stringstream castedItemCount;
	castedItemCount << itemCount[i];
	std::string returnedString = castedItemCount.str();
	
	return returnedString;
}

int Inventory::getItemCountInInt(std::string nameOfItem)
{
	return 0;
}

//int Inventory::increaseItemCount(int i, int value)
//{
//	return itemCount[i] = value;
//}

int Inventory::increaseItemCount(std::string nameOfItem)
{	
	if (std::find(strVec.begin(), strVec.end(), nameOfItem) != strVec.end())
	{
		std::cout << "Inventory::increaseItemCOunt znalazlem item: " << nameOfItem << '\n';
		auto it = find(strVec.begin(), strVec.end(), nameOfItem);
		int index = it - strVec.begin();
		std::cout << "pozycja: " << nameOfItem << " = " << index << '\n';
		return ++itemCount[index];
	}




	//else if (nameOfItem == "Heal Potion")//najpierw ++ a potem return �eby �atwiej wy�wietla� w konsoli, p�niej mo�na zmieni� na return ++itemCount[...]
	//{
	//	++itemCount[0];
	//	//std::cout << "HPgetItemCOunt string: " << getItemCountInString(0) << '\n';
	//	return itemCount[0];
	//}
	//else if (nameOfItem == "Mana Potion")
	//{
	//	++itemCount[1];
	//	std::cout << "increaseItemCount MP getItemCOunt string: " << getItemCountInString(1) << '\n';
	//	std::cout << "increaseItemCount MP itemCount[1]" << itemCount[1] << '\n';
	//	return itemCount[1];
	//}
	//else if (nameOfItem == "Speed Potion")
	//{
	//	++itemCount[2];
	//	//std::cout << "SPgetItemCOunt string: " << getItemCountInString(2) << '\n';
	//	return itemCount[2];
	//}
	return 0;

}

bool Inventory::getSwitchInv()
{
	return switchInv;
}

int Inventory::getItemAmount()
{
	return itemAmount;
}