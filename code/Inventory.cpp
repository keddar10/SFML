#include "Inventory.h"
#include "Item2.h"
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
			//std::cout << "NOT UNIQUE" << '\n';//OK
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
		//std::cout << "Inventory::addItemToInventory() isItemNameUnique false" << '\n';
		
		showedCounter[getItemSlot(itemName) /*- 1*/].str("");//zerowanie stringa
		//showedCounter[getItemSlot(itemName)/*-1*/] <<"x"<< increaseItemCount(itemName);
		increaseItemCount(itemName);
		showedCounter[getItemSlot(itemName)/*-1*/] <<"x"<< itemCount[getItemSlot(itemName)];
		counterVis[getItemSlot(itemName)/*-1*/].setFont(arial);
		counterVis[getItemSlot(itemName)/*-1*/].setPosition(static_cast<float>(WINDOW_WIDTH-characterSize-7), static_cast<float>((getItemSlot(itemName)+1)*itemVerticalDistanceInInventory));//OK
		counterVis[getItemSlot(itemName)/*-1*/].setCharacterSize(characterSize);
		counterVis[getItemSlot(itemName)/*-1*/].setString(showedCounter[getItemSlot(itemName)/*-1*/].str());

	}
	else
	{
		//increaseItemCount(itemName);
		//przy dodaniu nowego itemu czyszczeniue showedCounter[getItemSlot]?
		
		//std::cout << "Inventory::addItemToInventory() getItemSlot: " << getItemSlot(itemName) << '\n';
		//showedCounter[getItemSlot(itemName)].str("");
		//showedCounter[getItemSlot(itemName)] << " ";
		//counterVis[getItemSlot(itemName)/*-1*/].setFont(arial);
		//counterVis[getItemSlot(itemName)/*-1*/].setPosition(static_cast<float>(WINDOW_WIDTH - characterSize - 7), static_cast<float>((getItemSlot(itemName) + 1) * itemVerticalDistanceInInventory));//OK
		//counterVis[getItemSlot(itemName)/*-1*/].setCharacterSize(characterSize);
		//counterVis[getItemSlot(itemName)/*-1*/].setString(showedCounter[getItemSlot(itemName)/*-1*/].str());
		//std::cout << "Inventory::addItemToInventory() showedCounter.str(""): " << showedCounter[getItemSlot(itemName)].str() << '\n';
		
		itemSlot++;
		itemVis[itemAmount].setFont(arial);
		itemVis[itemAmount].setPosition(invVis.getPosition().x, static_cast<float>((itemSlot)*itemVerticalDistanceInInventory));
		itemVis[itemAmount].setCharacterSize(characterSize);
		itemVis[itemAmount].setString(showedItem[itemAmount].str());
		setItemSlot(itemName, itemSlot);
		//itemCount[itemSlot-1]++;//tylko zeby ilosc wyswietlana sie zgadzala, przerzucam spod increaseItemCount() pod setItemSLot()
		if (itemSelector !=0)
		{
			inventoryIndex.setPosition(inventoryIndex.getPosition().x, static_cast<float>(((itemSelector + 1) * itemVerticalDistanceInInventory) - characterSize / 2));
		}
		itemAmount++;
	}
}



void Inventory::setItemSlot(std::string itemNameset, int positionInEq)
{
	strVec.push_back(itemNameset);//tutaj przekazuje nazwe itemu
	intVec.push_back(positionInEq);//tutaj przekazuje itemSlot
	//moze przekaze tutaj inreaseItemCount? 
	itemCount.push_back(1);//to przechowuje iloœæ itemow, zawsze push_back 1?
	//std::cout << "Inventory::setItemSlot NAME= " << itemNameset << " POSITION = " << positionInEq << '\n';
}

unsigned int Inventory::getItemSlot(std::string itemNameget)
{
	std::vector<int>::size_type sizeOfVector = strVec.size();
	
	for (unsigned int i = 0; i < sizeOfVector; i++)
	{
		if (itemNameget == strVec[i])//TODO xd
		{
			return i/*+1*/;
			//break;
		}
	}
	return 0;
}
unsigned int Inventory::getItemSlot(int counter)
{
	//std::cout << "getItemSlot int counter: " << intVec[counter] << '\n';
	return intVec[counter];
}

void Inventory::replaceItemNames()
{
	for (int i = 0; i < itemAmount; i++)
	{
		showedItem[i].str("");
		showedItem[i] << strVec[i];
		itemVis[i].setFont(arial);
		itemVis[i].setPosition(invVis.getPosition().x, static_cast<float>((itemSlot)*itemVerticalDistanceInInventory));
		itemVis[i].setCharacterSize(characterSize);
		itemVis[i].setString(showedItem[i].str());

		showedCounter[i].str("");
		showedCounter[i] << "x" << itemCount[i];
		counterVis[i].setFont(arial);
		counterVis[i].setPosition(static_cast<float>(WINDOW_WIDTH - characterSize - 7), static_cast<float>((getItemSlot(strVec[i]) + 1) * itemVerticalDistanceInInventory));//OK
		counterVis[i].setCharacterSize(characterSize);
		counterVis[i].setString(showedCounter[i].str());
	}
}

void Inventory::substractItemAmount(int itemAmountArray)
{
	if (itemAmountArray == 0 && itemAmount != 0 && itemSelector != 0)
	{
		uint8_t offset = itemSelector - 1;//usuwam "-1" przy item selector
		std::rotate(intVec.begin() + offset, intVec.begin() + itemSelector, intVec.end());//przerzuca aktualny item na sam koniec wektora jako indeks
		intVec.pop_back();//tu usuwa ten item jako indeks
		std::rotate(strVec.begin() + offset, strVec.begin() + itemSelector, strVec.end());//item na koneic wektora jako nazwa
		strVec.pop_back();//usuwa item jako nazwe

		std::rotate(itemCount.begin() + offset, itemCount.begin() + itemSelector, itemCount.end());
		itemCount.pop_back();
		itemAmount--;
		itemSlot--;
		if(itemSelector > itemAmount)
		{
			itemSelector--;
		}
		//przyporzadkowanie itemVis dla nowych itemów (nowej kolejnosci), po usunieciu ostatniego elementu mam nowy strVec, te wartoœci strVec[0] musza byc takie jak itemVis[0]
		if (itemAmount != 0) 
		{
			replaceItemNames();
		}

		if (itemSelector != 0)
		{
			inventoryIndex.setPosition(inventoryIndex.getPosition().x, static_cast<float>(((itemSelector + 1) * itemVerticalDistanceInInventory) - characterSize / 2));//dodaje "+1" przy itemSelector
		}

		std::cout << "Inventory::substractItemAmount itemAmount = " << itemAmount << '\n';
	}
}

void Inventory::deleteItem(Item2* itemUsed)
{
	//TODO na nowo podjac sie usuwania/uzywania itemow
	std::cout << '\n';
	std::cout << "deleteItem() itemSelector: " << itemSelector<<'\n';
	if (switchInv && itemSelector == 0 && itemCount[itemSelector] > 0)//dobrze by bylo to usunac i zostawic sam warunek itemSelector > 0
	{	
		std::cout << "deleteItem() ->pierwszy if\n";
		std::cout << "deleteItem()intVec: item used int: " << intVec[itemSelector] << '\n';
		std::cout << "deleteItem()strVec: item used str: " << strVec[itemSelector] << '\n';
		itemCount[itemSelector]--;
		decreaseItemCount(strVec[itemSelector]);
		substractItemAmount(itemCount[itemSelector]);
		if (!itemCount.empty() && itemSelector > itemAmount)//tylko kontrolnie
		{
			std::cout << "deleteItem(): itemCount[i]after subtraction: " << itemCount[itemSelector] << "\n\n";
		}
		itemUsed->useEffect();
	}
	else if (switchInv && itemSelector > 0  && itemCount[itemSelector-1] > 0)
	{
		std::cout << "deleteItem() ->drugi if\n";
		std::cout << "deleteItem()intVec: item used int: " << intVec[itemSelector-1] << '\n';
		std::cout << "deleteItem()strVec: item used str: " << strVec[itemSelector-1] << '\n';
		itemCount[itemSelector - 1]--;
		decreaseItemCount(strVec[itemSelector - 1]);
		substractItemAmount(itemCount[itemSelector-1]);
		if (!itemCount.empty() && itemSelector - 1 > itemAmount)//tylko kontrolnie
		{
			std::cout << "deleteItem(): itemCount[i]after subtraction: " << itemCount[itemSelector - 1] << "\n\n";
		}
		itemUsed->useEffect();
	}
	else 
	{ 
		std::cout << "deleteItem(): brak itemu" << '\n'; 
	}
}

void Inventory::resetItemSelector()
{
	if (itemSelector >= itemSlot)//zmieniam > na >=
	{
		itemSelector = 0;//zmieniam z 1 na 0
		std::cout << "Inventory::resetItemSelector() is called" << '\n';
	}
}

void Inventory::selectItem(sf::Event& eventCalled)
{
	if (switchInv && eventCalled.type == sf::Event::KeyReleased && eventCalled.key.code == sf::Keyboard::J && itemSlot != 0)
	{
		resetItemSelector();
		for (int i = 0; i<itemAmount;i++)//tylko do kontroli
		{
			std::cout << "intVec["<<i<<"]: " << intVec[i]<<'\n';
			std::cout << "strVec["<<i<<"]: " << strVec[i]<<'\n';
			std::cout << "itemCount[" << i << "]: " << itemCount[i] << '\n';
		}
		std::cout << "selectItem(): itemSlot: " << itemSlot << '\n';
		std::cout << "selectItem()intVec: selected item int:" << intVec[itemSelector] << '\n';
		std::cout << "selectItem()strVec: selected item str:" << strVec[itemSelector] << '\n';
		std::cout << "selectItem(): selected item itemCount:" << itemCount[itemSelector] << '\n';
		
		++itemSelector;
		inventoryIndex.setPosition(inventoryIndex.getPosition().x, static_cast<float>(/*getItemSlot(itemSelector) **/((itemSelector+1) * itemVerticalDistanceInInventory)-characterSize/2));//dodaje "+1" przy itemSelector
		std::cout << "selectItem() itemSelector: " << itemSelector<<'\n';
		
	}	
}

std::string Inventory::getItemCountInString(int i)//zamiana itemCount na string - nieujzywane teraz
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

void Inventory::decreaseItemCount(std::string itemName)
{
	if (itemSelector != 0)
	{
		std::cout << "Inventory::decreaseItemCount\n";
		showedCounter[getItemSlot(itemName) /*- 1*/].str("");//zerowanie stringa
		showedCounter[getItemSlot(itemName)/*-1*/] << "x" << itemCount[itemSelector - 1];
		counterVis[getItemSlot(itemName)/*-1*/].setFont(arial);
		counterVis[getItemSlot(itemName)/*-1*/].setPosition(static_cast<float>(WINDOW_WIDTH - characterSize - 7), static_cast<float>((getItemSlot(itemName) + 1) * itemVerticalDistanceInInventory));//OK
		counterVis[getItemSlot(itemName)/*-1*/].setCharacterSize(characterSize);
		counterVis[getItemSlot(itemName)/*-1*/].setString(showedCounter[getItemSlot(itemName)/*-1*/].str());
	}
}

int Inventory::increaseItemCount(std::string nameOfItem)
{	
	if (std::find(strVec.begin(), strVec.end(), nameOfItem) != strVec.end())
	{
		std::cout << "Inventory::increaseItemCOunt znalazlem kolejny item: " << nameOfItem << '\n';
		auto it = find(strVec.begin(), strVec.end(), nameOfItem);
		int index = it - strVec.begin();
		std::cout << "pozycja: " << nameOfItem << " = " << index << '\n';
		return ++itemCount[index];
	}
	return 0;
}

bool Inventory::getSwitchInv()
{
	return switchInv;
}

int Inventory::getItemCount()
{
	return itemAmount;
}

void Inventory::showItemSelectorValue()
{
	std::cout << "Inventory::showItemSelectorValue(): " << itemSelector << '\n';
	for (int i = 0; i<itemAmount;i++)
	{
		std::cout << "Inventory::showItemSelectorValue(): itemCount[" << i << "] " << itemCount[i] << '\n';
	}
}