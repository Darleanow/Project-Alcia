#include "Hero.h"

#include "god.h"
#include "system_related.h"


////////////////////////////////////////////////////////////////////////////////
///									Darleanow								 ///
///																			 ///
///						Hero related functions // Inventory // Combat        ///
///																			 ///
////////////////////////////////////////////////////////////////////////////////


//Return hero's hp      ////////////
int Hero::get_hp()			     ///
{							     ///
	return this->hp;		     ///
}							     ///
int Hero::get_max_hp()
{
	return this->max_hp;
}
								 ///
void Hero::set_hp(int quantity)  ///
{								 ///
	this->hp += quantity;		 ///
}								 ///
////////////////////////////////////


//Set name and return name		/////////////
void Hero::set_name(std::string name)	  ///
{										  ///
	this->name = name;					  ///
}										  ///
										  ///
std::string Hero::get_name()              ///
{										  ///
	return this->name;					  ///
}										  ///
										  ///
void Hero::take_dmg(int quantity)		  ///
{										  ///
	this->hp -= quantity;				  ///
}										  ///
/////////////////////////////////////////////

void Hero::give_gold(int quantity)
{
	this->gold += quantity;
}

//Get items				////////////////////////////////////////////////////
void Hero::give(Item* item, int amount)							 ///
{																		 ///
	bool found = false;													 ///
	for (size_t search = 0; search < this->inventory.size(); search++)		 ///
	{																	 ///
		if (this->inventory[search]->get_name() == item->get_name())			     ///
		{																 ///
			found = true;												 ///
			break;														 ///
		}																 ///
	}																	 ///
	item->add_quantity(amount);									 ///
	if (!found)															 ///
	{																	 ///
		this->inventory.push_back(item);								 ///
	}																	 ///
}																		 ///
////////////////////////////////////////////////////////////////////////////

//Main menu actions			////////////////////////////////////////////////
void Hero::display_actions()											 ///
{																		 ///
	std::string choice = "0";											 ///
	while (!(choice == "1" || choice == "2" || choice == "3"))			 ///
	{																	 ///
		cls();															 ///
		std::cout << "[PROJECT:ALCIA]" << std::endl;					 ///
		std::cout << "What do you want to do ?" << std::endl;			 ///
		std::cout << "1. Search for a Monster" << std::endl;			 ///
		std::cout << "2. Go back in Town" << std::endl;					 ///
		std::cout << "3. Check your Inventory" << std::endl;			 ///
		std::cout << "Your choice: ";									 ///
		std::cin >> choice;												 ///
	}																	 ///
																		 ///
	cls();																 ///
																		 ///
	if (choice == "1")													 ///
	{
		this->combat_main();
	}
	else if (choice == "2")
	{
		this->show_Town_actions();
	}
	else if (choice == "3")
	{
		show_actions_inventory();
	}
}

int Hero::get_level()
{
	return this->level;
}


int Hero::combat_main()
{
	std::string method_select;
	auto* monster = generate_monster(this);
	while (method_select != "1" && method_select != "2")
	{
		std::cout << "[PLAINS]" << std::endl;
		std::cout << "1. Search for a random monster" << std::endl;
		std::cout << "2. Farm a monster (At your own risks)" << std::endl << std::endl;

		std::cout << "Choice: ";
		std::cin >> method_select;
		cls();
		std::cout << "[PLAINS]" << std::endl;
		if (method_select == "2")
		{
			std::string monster_choice = "ANTIBUG";
			while (!(is_digits(monster_choice)))
			{
				std::cout << "1. Zombie" << std::endl;
				std::cout << "2. Skeletton" << std::endl;
				std::cout << "3. Troll" << std::endl;
				std::cout << "4. Super Troll" << std::endl;
				std::cout << "5. Kobold" << std::endl;
				std::cout << "6. Oreade" << std::endl;
				std::cout << "7. Baby Dragon" << std::endl;
				std::cout << "8. Mama Dragon" << std::endl;
				std::cout << std::endl << std::endl << "Enter monster number to fight it or 'quit' to quit" << std::endl;

				std::cout << "Choice: ";
				std::cin >> monster_choice;
				if (monster_choice == "quit")
				{
					return 0;
				}
				if (is_digits(monster_choice) && std::stoi(monster_choice) <= 8 && std::stoi(monster_choice) >= 1)
				{
					if (monster_choice == "1")
						monster = new Zombie;
					else if (monster_choice == "2")
						monster = new Skeletton;
					else if (monster_choice == "3")
						monster = new Troll;
					else if (monster_choice == "4")
						monster = new SuperTroll;
					else if (monster_choice == "5")
						monster = new Kobold;
					else if (monster_choice == "6")
						monster = new Oreade;
					else if (monster_choice == "7")
						monster = new BabyDragon;
					else if (monster_choice == "8")
						monster = new MamaDragon;
					cls();
				}
			}
		}
		else
		{
			cls();
			break;
		}
	}

	bool fight = true;
	while (monster->get_hp() > 0 && this->get_hp() > 0)
	{
		std::string choice = "0";
		while (choice == "0" || (choice != "1" && choice != "2" && choice != "3"))
		{
			std::cout << "[COMBAT]" << std::endl;
			std::cout << std::endl;
			std::cout << monster->get_name() << " :" << std::endl;
			std::cout << "| Hp: " << monster->get_hp() << " / " << monster->get_max_hp() << std::endl;
			std::cout << "| Attack: " << monster->get_atk() << std::endl;
			std::cout << std::endl << std::endl;
			std::cout << this->get_name() << " :" << std::endl;
			std::cout << "| Hp: " << this->get_hp() << " / " << this->get_max_hp() << std::endl;
			std::cout << "| Attack: " << this->get_atk() << std::endl;
			std::cout << std::endl << std::endl << std::endl;
			std::cout << "What do you want to do ?" << std::endl;
			std::cout << "1.Attack" << std::endl;
			std::cout << "2.Use an item" << std::endl;
			std::cout << "3.Run (10% chance)" << std::endl;
			std::cout << "Choice: ";
			std::cin >> choice;
			cls();
		}
		if (choice == "1")
		{
			monster->take_dmg(this);
		}
		else if (choice == "2")
		{
			this->show_useable_items();
		}
		else if (choice == "3")
		{
			this->take_dmg(monster->get_atk());
			if (generate_random_number(0, 100) <= 10)
			{
				fight = false;
				break;
			}
		}
	}

	cls();
	if (fight)
	{
		if (monster->get_hp() <= 0)
		{
			this->atk -= 15 * strength_potions_used;
			this->strength_potions_used = 0;

			std::cout << color("rare") << "[VICTORY]" << color("def") << std::endl;
			std::cout << "[DROPS]" << std::endl;
			std::cout << "You've got:" << std::endl;
			monster->drop(this);
			int will_drop = generate_random_number(0, 100);
			if (will_drop <= 30)
			{
				std::vector<std::string> killing_sentences = { "cutting in half",
					"ripping off", "dismembering" };
				std::cout << std::endl << std::endl;
				std::cout << "While you were " << killing_sentences[generate_random_number(0, 2)]
					<< " your enemy, you saw a chest.." << std::endl << "You opened it and found:";
				auto item = generate_item();
				std::cout << color(item->get_rarity()) << item->get_name() << color("def");
				if (this->check(item->get_name()))
				{
					this->add(item->get_name(), 1);
				}
				else
				{
					this->give(item);
				}
				std::cout << std::endl << std::endl;
				std::cout << "Press enter to continue. . .";
				getchar();
				cls();
			}

			if (this->compute_xp_needed() == 0)
			{
				this->level_up();
				this->xp_to_levelup = this->get_xp_to_lvl();
			}
		}
		else
		{
			std::cout << color("red") << "[DEFEAT]" << color("def") << std::endl;
			std::cout << "Press enter to exit. . ." << std::endl;
			getchar();
			exit(BYE_THANKS_4_PLAY);
		}
	}
	cls();
	return 0;
}

void Hero::remove_elem(int index, int amount)
{
	if (amount > 0)
	{
		int rest = this->inventory[index]->get_quantity();
		rest -= amount;
		this->inventory[index]->set_quantity(rest);
		if (this->inventory[index]->get_quantity() <= 0)
		{
			this->inventory.erase(this->inventory.begin() + index);
		}
	}

}

void Hero::rem_by_name(std::string name, int quantity)
{
	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i]->get_name() == name)
		{
			this->remove_elem(i, quantity);
		}
	}
}


void Hero::delete_an_item()
{
	cls();

	std::string quantity_to_delete;
	std::string delete_choice;
	while (delete_choice < "1" || static_cast<size_t>(delete_choice[0] - 49) >= this->inventory.size())
	{
		this->show_inventory();
		std::cout << "Choose an element you want to delete (the number left to the item name) or 'quit' to quit: ";
		std::cin >> delete_choice;
		if (delete_choice == "quit")
		{
			break;
		}
		if (static_cast<size_t>(delete_choice[0] - 49) < this->inventory.size())
		{
			std::cout << std::endl;
			std::cout << "Enter amount to delete or 'cancel' to cancel: ";
			std::cin >> quantity_to_delete;
			if (quantity_to_delete != "cancel")
			{
				this->remove_elem(static_cast<int>(delete_choice[0] - 49), stoi(quantity_to_delete));

			}
			else
			{
				delete_choice = "-1";
			}
		}
		cls();
	}

}

void Hero::equip(Item* item)
{
	if (item->get_type() == "right_hand")
	{
		if (!(right_hand.empty()))
		{
			this->give(right_hand[0]);
			right_hand.clear();
		}
		right_hand.push_back(item);
		this->atk += item->get_atk();
	}
	else if (item->get_type() == "helmet")
	{
		if (!(helmet.empty()))
		{
			this->give(helmet[0]);
			helmet.clear();
		}
		helmet.push_back(item);
		this->max_hp += item->get_hp();
		this->hp += item->get_hp();
	}
	else if (item->get_type() == "chestplate")
	{
		if (!(chestplate.empty()))
		{
			this->give(chestplate[0]);
			chestplate.clear();
		}
		chestplate.push_back(item);
		this->max_hp += item->get_hp();
		this->hp += item->get_hp();
	}
	else if (item->get_type() == "leggings")
	{
		if (!(pants.empty()))
		{
			this->give(pants[0]);
			pants.clear();
		}
		pants.push_back(item);
		this->max_hp += item->get_hp();
		this->hp += item->get_hp();
	}
	else if (item->get_type() == "boots")
	{
		if ((!boots.empty()))
		{
			this->give(boots[0]);
			boots.clear();
		}
		boots.push_back(item);
		this->max_hp += item->get_hp();
		this->hp += item->get_hp();
	}
	this->remove_from_inventory(item);
}

void Hero::unequip(int choice)
{
	if (choice == 1)
	{
		this->give(right_hand[0]);
		this->atk -= right_hand[0]->get_atk();
		right_hand.clear();
	}
	else if (choice == 2)
	{
		this->give(helmet[0]);
		this->max_hp -= helmet[0]->get_hp();
		this->hp -= helmet[0]->get_hp();
		helmet.clear();
	}
	else if (choice == 3)
	{
		this->give(chestplate[0]);
		this->max_hp -= chestplate[0]->get_hp();
		this->hp -= chestplate[0]->get_hp();
		chestplate.clear();
	}
	else if (choice == 4)
	{
		this->give(pants[0]);
		this->max_hp -= pants[0]->get_hp();
		this->hp -= pants[0]->get_hp();
		pants.clear();
	}
	else if (choice == 5)
	{
		this->give(boots[0]);
		this->max_hp -= boots[0]->get_hp();
		this->hp -= boots[0]->get_hp();
		boots.clear();
	}
}

void Hero::prompt_unequip()
{
	std::cout << "Equipped Items: " << std::endl;
	std::vector<int> valid_unequip;
	if (!(right_hand.empty()))
	{

		std::cout << "[1] | Right hand:  " << color(right_hand.back()->get_rarity()) << right_hand.back()->get_name() << color("def") << std::endl;
		valid_unequip.push_back(1);
	}
	if (!(helmet.empty()))
	{
		std::cout << "[2] | Helmet:  " << color(helmet.back()->get_rarity()) << helmet.back()->get_name() << color("def") << std::endl;
		valid_unequip.push_back(2);
	}
	if (!(chestplate.empty()))
	{
		std::cout << "[3] | Chestplate:  " << color(chestplate.back()->get_rarity()) << chestplate.back()->get_name() << color("def") << std::endl;
		valid_unequip.push_back(3);
	}
	if (!(pants.empty()))
	{
		std::cout << "[4] | Pants:  " << color(pants.back()->get_rarity()) << pants.back()->get_name() << color("def") << std::endl;
		valid_unequip.push_back(4);
	}
	if (!(boots.empty()))
	{
		std::cout << "[5] | Boots:  " << color(boots.back()->get_rarity()) << boots.back()->get_name() << color("def") << std::endl;
		valid_unequip.push_back(5);
	}
	if (!(valid_unequip.size() < 1))
	{
		bool is_valid = false;
		int choice = 0;
		while (!(is_valid))
		{
			std::cout << "Enter number from the equipement you want to unequip" << std::endl;
			std::cout << "Choice: ";
			std::cin >> choice;
			for (size_t it = 0; it < valid_unequip.size(); it++)
			{
				if (choice == valid_unequip[it])
				{
					is_valid = true;
					break;
				}
			}
		}
		unequip(choice);
		cls();
		prompt_unequip();
	}
	else
	{
		cls();
		show_actions_inventory();
	}
}

void Hero::remove_from_inventory(Item* item)
{
	for (size_t search = 0; search < this->inventory.size(); search++)
	{
		if (this->inventory[search]->get_name() == item->get_name())
		{
			this->remove_elem(search, 1);
			break;
		}
	}
}

void Hero::show_inventory()
{
	std::cout << "[INVENTORY]" << std::endl;
	for (size_t items = 0; items < this->inventory.size(); items++)
	{
		std::cout << items + 1 << ". " << color(this->inventory[items]->get_rarity()) << this->inventory[items]->get_name() << color("def") << " | " << this->inventory[items]->get_quantity() << std::endl;
	}
	if (this->inventory.size() == 0)
	{
		std::cout << "  [EMPTY]";
	}
	std::cout << std::endl;
}

bool Hero::check(std::string name)
{
	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i]->get_name() == name)
		{
			return true;
		}
	}
	return false;
}

int Hero::check_quant(std::string item_name)
{
	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i]->get_name() == item_name)
		{
			return this->inventory[i]->get_quantity();
		}
	}
	return 0;
}

void Hero::add(std::string name, int amount)
{
	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i]->get_name() == name)
		{
			this->inventory[i]->add_quantity(amount);
			break;
		}
	}
}

void Hero::show_equipeable_items()
{
	std::vector<Item*> equipeable_items;
	for (size_t iter = 0; iter < this->inventory.size(); iter++)
	{
		if (this->inventory[iter]->get_type() != "type" && this->inventory[iter]->get_type() != "loot" && this->inventory[iter]->get_type() != "potion")
		{
			equipeable_items.push_back(this->inventory[iter]);
		}
	}
	cls();
	std::string choice = "0";

	if (equipeable_items.size())
	{

		while (choice != "-1" && !equipeable_items.empty())
		{
			std::cout << "[EQUIP POSSIBLE]" << std::endl;
			for (size_t iter_equip = 0; iter_equip < equipeable_items.size(); iter_equip++)
			{
				std::cout << iter_equip + 1 << ". " <<
					"[" << equipeable_items[iter_equip]->get_type() << "] " << color(equipeable_items[iter_equip]->get_rarity()) << equipeable_items[iter_equip]->get_name() << color("def") << std::endl;
			}
			std::cout << "Enter item number to equip it or 'quit' to quit !" << std::endl;
			std::cout << "Choice: ";
			std::cin >> choice;
			if (choice != "quit" && static_cast<size_t>(choice[0]) - 49 < equipeable_items.size())
			{
				this->equip(equipeable_items[static_cast<int>(choice[0]) - 49]);
				int temp = static_cast<int>(choice[0]) - 49;
				equipeable_items.erase(equipeable_items.begin() + temp);
			}
			if (choice == "quit" || equipeable_items.empty())
			{
				break;
			}
			cls();
		}
	}
}

void Hero::show_useable_items()
{
	std::vector<Item*> potions;
	for (size_t i = 0; i < this->inventory.size(); i++)
	{
		if (this->inventory[i]->get_type() == "potion")
		{
			potions.push_back(this->inventory[i]);
		}
	}
	if (potions.size() < 1)
	{
		std::cout << "No items to use." << std::endl;
		std::cout << "Press enter to continue. . .";
		getchar();
		cls();
	}
	else
	{
		std::string choice = "0";
		while (choice == "0" && (static_cast<size_t>(choice[0] - 49) > potions.size()))
		{
			std::cout << "[USEABLES]" << std::endl;
			for (size_t i = 0; i < potions.size(); i++)
			{
				std::cout << i + 1 << ". " << color(potions[i]->get_rarity()) << potions[i]->get_name() << color("def") << " x " << potions[i]->get_quantity() << std::endl;
			}
			std::cout << std::endl << std::endl;
			std::cout << "Enter quit/exit to cancel." << std::endl;
			std::cout << "Your choice: ";
			std::cin >> choice;
			if ((static_cast<size_t>(choice[0] - 49) <= potions.size() &&
				static_cast<size_t>(choice[0] - 49) >= 0) || choice == "quit" || choice == "exit")
			{
				if (choice != "quit" && choice != "exit")
				{
					if (potions[static_cast<int>(choice[0] - 49)]->get_name() == "Health Potion")
					{
						this->hp += potions[static_cast<int>(choice[0] - 49)]->get_hp();
						if (this->hp > this->max_hp)
						{
							this->hp = this->max_hp;
						}
						this->remove_from_inventory(potions[static_cast<int>(choice[0] - 49)]);
						cls();
					}
					else if (potions[static_cast<int>(choice[0] - 49)]->get_name() == "Strength Potion")
					{
						this->atk += potions[static_cast<int>(choice[0] - 49)]->get_atk();
						this->strength_potions_used += 1;
					}
				}
				break;
			}
			cls();
		}
	}

}


void Hero::show_actions_inventory()
{
	int second_choice = 0;
	while (!(second_choice == 1 || second_choice == 2 || second_choice == 3 || second_choice == 4 || second_choice == 5 || second_choice == 6))
	{
		cls();
		show_inventory();

		std::cout << std::endl;
		std::cout << "[STATS]" << std::endl;
		std::cout << "Level: " << this->level << " | Xp to level up: " << this->compute_xp_needed() << std::endl;
		std::cout << "Gold: " << this->gold << std::endl;
		std::cout << "Hp: " << this->hp << "/" << this->max_hp << std::endl;
		std::cout << "Attack: " << this->get_total_dmg() << std::endl << std::endl;

		std::cout << "[EQUIPEMENT]" << std::endl;

		std::cout << (this->right_hand.empty() ? "Hand: Empty !" : "Hand: " + color(this->right_hand.back()->get_rarity())
					  + this->right_hand.back()->get_name() + color("def") +
					  " || Bonus: " + std::to_string(this->right_hand.back()->get_atk()) + " atk") << std::endl;

		std::cout << (this->helmet.empty() ? "Helmet: Empty !" : "Helmet: " + color(this->helmet.back()->get_rarity())
					  + this->helmet.back()->get_name() + color("def") +
					  " || Bonus: " + std::to_string(this->helmet.back()->get_hp()) + " hp") << std::endl;

		std::cout << (this->chestplate.empty() ? "Chest: Empty !" : "Chest: " + color(this->chestplate.back()->get_rarity())
					  + this->chestplate.back()->get_name() + color("def") +
					  " || Bonus: " + std::to_string(this->chestplate.back()->get_hp()) + " hp") << std::endl;

		std::cout << (this->pants.empty() ? "Pants: Empty !" : "Pants: " + color(this->pants.back()->get_rarity())
					  + this->pants.back()->get_name() + color("def") +
					  " || Bonus: " + std::to_string(this->pants.back()->get_hp()) + " hp") << std::endl;

		std::cout << (this->boots.empty() ? "Boots: Empty !" : "Boots: " + color(this->boots.back()->get_rarity())
					  + this->boots.back()->get_name() + color("def") +
					  " || Bonus: " + std::to_string(this->boots.back()->get_hp()) + " hp") << std::endl << std::endl;

		std::cout << "[ACTIONS]" << std::endl;
		std::cout << "What do you want to do ?" << std::endl;
		std::cout << "1. Use an Item" << std::endl;
		std::cout << "2. Equip something" << std::endl;
		std::cout << "3. Unequip something" << std::endl;
		std::cout << "4. Throw away an item" << std::endl;
		std::cout << "5. Quit Inventory" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> second_choice;

	}

	cls();

	if (second_choice == 1)
	{
		this->show_useable_items();
		this->show_actions_inventory();
	}
	else if (second_choice == 2)
	{
		this->show_equipeable_items();
	}
	else if (second_choice == 3)
	{
		this->prompt_unequip();
	}
	else if (second_choice == 4)
	{
		this->delete_an_item();
		this->show_actions_inventory();
	}
	else if (second_choice == 5)
	{
		cls();
		this->display_actions();
	}
}

void Hero::show_Town_actions()
{
	int town_choice = 0;
	while (!(town_choice == 1 || town_choice == 2 || town_choice == 3))
	{
		std::cout << "[TOWN]" << std::endl;
		std::cout << "1. Go into the Forge" << std::endl;
		std::cout << "2. Go into the Shop" << std::endl;
		std::cout << "3. Leave town" << std::endl;
		std::cout << "Your choice: ";
		std::cin >> town_choice;
	}

	cls();

	if (town_choice == 1)
	{
		this->show_black_smith_actions();
	}
	else if (town_choice == 2)
	{
		this->show_shop_options();
	}
	else
	{
		this->display_actions();
	}
}

void Hero::show_black_smith_actions()
{
	std::vector<std::string> item_names
	{
		"Common Sword", "Rare Sword", "Epic Sword", "Legendary Sword",
		"Common Helmet", "Rare Helmet", "Epic Helmet", "Legendary Helmet",
		"Common Chestplate", "Rare Chestplate", "Epic Chestplate", "Legendary Chestplate",
		"Common Leggings", "Rare Leggings", "Epic Leggings", "Legendary Leggings",
		"Common Boots","Rare Boots","Epic Boots", "Legendary Boots",
	};

	//Objects init
	zombie_flesh flesh;	zombie_eye eye;
	bone_shard shards; bones bones;
	troll_belt belt; troll_finger finger;
	empty_sack sack;
	kobold_scepter scepter; kobold_tails tails;
	oreade_powder powder; magic_fragments fragments;
	dragon_scale scale; dragon_tooth tooth;

	std::vector<std::unordered_map<Item*, int>> recipes
	{
		{{&flesh,10},{&eye,4}},		{{&flesh,20},{&eye,10}},	{{&belt,2},{&sack,4},{&bones,15}},				{{&scepter,15},{&tooth,3},{&finger,25},{&fragments,40},{&bones,100}},
		{{&shards,5},{&bones,10}},	{{&shards,18},{&bones,15}},	{{&shards,35},{&bones,24},{&sack,2}},			{{&powder,12},{&fragments,4},{&scale,2},{&bones,67}},
		{{&shards,15},{&bones,21}},	{{&shards,24},{&bones,21}},	{{&tails,4},{&fragments,2},{&scale,3},{&sack,10}},	{{&powder,19},{&tooth,3},{&scale,6},{&bones,95}},
		{{&shards,8},{&bones,14}},	{{&shards,21},{&bones,19}},	{{&tails,2},{&tooth,1},{&scale,1},{&sack,8}},	{{&powder,14},{&tooth,6},{&scale,5},{&bones,84}},
		{{&shards,4},{&flesh,10}},	{{&shards,7}, {&flesh,18}},	{{&finger,12},{&powder,8},{&sack,14}},			{{&powder,12},{&finger,4},{&scale,2},{&bones,54}},
	};

	std::string user_input;
	while (user_input != "quit")
	{
		std::cout << "[FORGE]" << std::endl;
		std::cout << "Welcome to the forge !" << std::endl << std::endl;

		std::cout << "[ITEM LIST]" << std::endl;
		for (size_t i = 0; i < item_names.size(); i++)
		{
			std::cout << i + 1 << ". " <<
				(!(item_names[i].find("Legendary")) ?
				 color("legendary") : !(item_names[i].find("Epic")) ?
				 color("epic") : !(item_names[i].find("Rare")) ?
				 color("rare") : color("common"))
				<< item_names[i] << color("def") << "  ";
			if (!item_names[i].find("Legendary"))
			{
				std::cout << std::endl;
			}
		}
		std::cout << std::endl << std::endl;
		std::cout << "Enter item number to view needed resources / craft it or 'quit' to exit" << std::endl;
		std::cout << "Choice: ";
		std::cin >> user_input;
		if (user_input == "quit" or !is_digits(user_input))
		{
			break;
		}
		else if (static_cast<size_t>(std::stoi(user_input) - 1) < item_names.size() && std::stoi(user_input) - 1 >= 0)
		{
			std::string choice;
			while (choice != "1" && choice != "2")
			{
				cls();
				std::cout << "[DETAILS]" << std::endl;
				std::cout << "[" << (!(item_names[std::stoi(user_input) - 1].find("Legendary")) ?
									 color("legendary") : !(item_names[std::stoi(user_input) - 1].find("Epic")) ?
									 color("epic") : !(item_names[std::stoi(user_input) - 1].find("Rare")) ?
									 color("rare") : color("common"))
					<< item_names[std::stoi(user_input) - 1] << color("def") << "]" << std::endl << std::endl;
				std::cout << "Needed items: " << std::endl;
				for (auto item : recipes[std::stoi(user_input) - 1])
				{
					std::cout << "- " << color(item.first->get_rarity()) << item.first->get_name() << color("def") << " x " << item.second;
					std::cout << " || " << "You have : " << check_quant(item.first->get_name()) << std::endl;
				}

				std::cout << std::endl;
				std::cout << "What do you want to do ?" << std::endl;
				std::cout << "1. Craft the item" << std::endl;
				std::cout << "2. Go back" << std::endl;
				std::cout << "Your choice: ";
				std::cin >> choice;
				if (choice == "2")
				{
					cls();
					break;
				}
				else if (choice == "1")
				{
					bool enough = true;
					for (auto item : recipes[std::stoi(user_input) - 1])
					{
						if (!(this->check_quant(item.first->get_name()) >= item.second))
						{
							enough = false;
							std::cout << "Not enough materials. . ." << std::endl;
							std::cout << "Press enter to continue. . .";
							getchar();
							cls();
							break;
						}
					}
					if (enough == true)
					{
						std::cout << "Successfully made the " << item_names[std::stoi(user_input) - 1] << std::endl;
						for (auto item : recipes[std::stoi(user_input) - 1])
						{
							this->rem_by_name(item.first->get_name(), item.second);
						}
						if (item_names[std::stoi(user_input) - 1] == "Common Sword")
							this->give(new Common_Sword);
						else if (item_names[std::stoi(user_input) - 1] == "Rare Sword")
							this->give(new Rare_Sword);
						else if (item_names[std::stoi(user_input) - 1] == "Epic Sword")
							this->give(new Epic_Sword);
						else if (item_names[std::stoi(user_input) - 1] == "Legendary Sword")
							this->give(new Legendary_Sword);
						else if (item_names[std::stoi(user_input) - 1] == "Common Helmet")
							this->give(new Common_Helmet);
						else if (item_names[std::stoi(user_input) - 1] == "Rare Helmet")
							this->give(new Rare_Helmet);
						else if (item_names[std::stoi(user_input) - 1] == "Epic Helmet")
							this->give(new Epic_Helmet);
						else if (item_names[std::stoi(user_input) - 1] == "Legendary Helmet")
							this->give(new Legendary_Helmet);
						else if (item_names[std::stoi(user_input) - 1] == "Common Chestplate")
							this->give(new Common_Chestplate);
						else if (item_names[std::stoi(user_input) - 1] == "Rare Chestplate")
							this->give(new Rare_Chestplate);
						else if (item_names[std::stoi(user_input) - 1] == "Epic Chestplate")
							this->give(new Epic_Chestplate);
						else if (item_names[std::stoi(user_input) - 1] == "Legendary Chestplate")
							this->give(new Legendary_Chestplate);
						else if (item_names[std::stoi(user_input) - 1] == "Common Leggings")
							this->give(new Common_Leggings);
						else if (item_names[std::stoi(user_input) - 1] == "Rare Leggings")
							this->give(new Rare_Leggings);
						else if (item_names[std::stoi(user_input) - 1] == "Epic Leggings")
							this->give(new Epic_Leggings);
						else if (item_names[std::stoi(user_input) - 1] == "Legendary Leggings")
							this->give(new Legendary_Leggings);
						else if (item_names[std::stoi(user_input) - 1] == "Common Boots")
							this->give(new Common_Boots);
						else if (item_names[std::stoi(user_input) - 1] == "Rare Boots")
							this->give(new Rare_Boots);
						else if (item_names[std::stoi(user_input) - 1] == "Epic Boots")
							this->give(new Epic_Boots);
						else if (item_names[std::stoi(user_input) - 1] == "Legendary Boots")
							this->give(new Legendary_Boots);
						std::cout << std::endl << "Press Enter to continue. . .";
						getchar();
						cls();
					}
				}
			}
		}
	}
}

void Hero::show_shop_options()
{

	std::string sel_choice;
	while (sel_choice != "1" && sel_choice != "2" && sel_choice != "3")
	{
		std::cout << "Welcome to the shop !" << std::endl;
		std::cout << "1. Buy Items" << std::endl;
		std::cout << "2. Sell Items" << std::endl;
		std::cout << "3. Leave shop" << std::endl;
		std::cout << std::endl << "Choice: ";
		std::cin >> sel_choice;
		cls();
	}
	if (sel_choice == "1")
	{
		std::vector<Item*> purchaseable_items =
		{
			new Common_Sword, new Common_Leggings, new Common_Helmet,
			new Common_Boots, new Common_Chestplate,
			new Rare_Boots, new Rare_Chestplate, new Rare_Helmet,
			new Rare_Leggings, new Rare_Sword,
			new health_potion, new strength_potion,
			new Epic_Sword, new Epic_Boots, new Epic_Chestplate, new Epic_Helmet,
			new Epic_Leggings,
			new Legendary_Boots, new Legendary_Chestplate, new Legendary_Helmet,
			new Legendary_Leggings, new Legendary_Sword
		};
		std::vector<size_t> odds =
		{
			1,1,1,
			1,1,
			1,1,1,
			1,1,
			2,
			static_cast<size_t>(this->level > 40 ? 1 : 0.01),
			static_cast<size_t>(this->level > 40 ? 1 : 0.001),
			static_cast<size_t>(this->level > 40 ? 1 : 0.001),
			static_cast<size_t>(this->level > 40 ? 1 : 0.001),
			static_cast<size_t>(this->level > 40 ? 1 : 0.001),
			static_cast<size_t>(this->level > 40 ? 1 : 0.001),

			static_cast<size_t>(this->level > 50 ? 0.1 : 0.0001),
			static_cast<size_t>(this->level > 50 ? 0.1 : 0.0001),
			static_cast<size_t>(this->level > 50 ? 0.1 : 0.0001),
			static_cast<size_t>(this->level > 50 ? 0.1 : 0.0001),
			static_cast<size_t>(this->level > 50 ? 0.1 : 0.0001),

		};
		std::vector<Item*> items =
		{
			random_item(purchaseable_items, odds),random_item(purchaseable_items, odds),
			random_item(purchaseable_items, odds),random_item(purchaseable_items, odds),
			random_item(purchaseable_items, odds),random_item(purchaseable_items, odds)
		};
		cls();
		std::cout << "[BUY]" << std::endl;
		for (size_t i = 0; i < items.size(); i++)
		{
			std::cout << "" << i + 1 << ". " << color(items[i]->get_rarity()) << items[i]->get_name() << color("def")
				<< "  Price: " << items[i]->get_price() << " golds" << std::endl;
		}
		std::cout << std::endl << std::endl;
		std::string choice;
		while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6" && choice != "exit"
			   && choice != "Exit" && choice != "quit" && choice != "Quit")
		{
			std::cout << "Enter item's number to purchase it, enter 'quit' to leave the shop" << std::endl;
			std::cout << std::endl;
			std::cout << "You have " << this->gold << " gold." << std::endl;
			std::cout << "Your choice:";
			std::cin >> choice;
			std::cout << std::endl;
			if (choice == "exit" || choice == "Exit" || choice == "quit" || choice == "Quit")
			{
				cls();
				this->show_shop_options();
			}
			if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6")
			{
				if (items[static_cast<int>(choice[0]) - 49]->get_price() > this->gold)
				{
					std::cout << "You're too poor to buy this :(" << std::endl;
					std::cout << "You can leave the shop or try again but it wont work !" << std::endl;
					std::cout << "Press enter to continue. . .";
					getchar();
					cls();
					this->show_shop_options();
				}
				else
				{
					this->gold -= items[static_cast<int>(choice[0]) - 49]->get_price();
					if (this->check(items[static_cast<int>(choice[0]) - 49]->get_name()))
					{
						this->add(items[static_cast<int>(choice[0]) - 49]->get_name(), 1);
					}
					this->give(items[static_cast<int>(choice[0]) - 49]);
					std::cout << "Successfully bought the item !" << std::endl;
					std::cout << "Press enter to continue. . .";
					getchar();
					cls();
					this->show_shop_options();
				}
			}
		}
	}
	else if (sel_choice == "2")
	{
		std::string choice;
		if (!this->inventory.empty())
		{
			while (choice != "quit" || !this->inventory.empty())
			{
				std::cout << "[SELL]" << std::endl;
				std::cout << "You have " << this->gold << " golds." << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				for (size_t i = 0; i < this->inventory.size(); i++)
				{
					std::cout << i + 1 << ". " << color(this->inventory[i]->get_rarity()) << this->inventory[i]->get_name() <<
						color("def") << " x " << this->inventory[i]->get_quantity() << " || " << this->inventory[i]->get_price() << " golds." << std::endl;
				}
				std::cout << std::endl << std::endl << "Enter item number, or 'quit' to go back" << std::endl;
				std::cout << std::endl << "Choice: ";
				std::cin >> choice;
				if (choice == "quit" || this->inventory.empty())
				{
					break;
				}
				else if (static_cast<size_t>(choice[0] - 49) < this->inventory.size() && static_cast<size_t>(choice[0] - 49) >= 0)
				{
					std::cout << "[SELECTED] -> " << color(this->inventory[static_cast<int>(choice[0] - 49)]->get_rarity())
						<< this->inventory[static_cast<int>(choice[0] - 49)]->get_name() << color("def") << std::endl;
					std::cout << std::endl << "Enter quantity or '0' to cancel" << std::endl;
					std::string quant;
					std::cout << "Choice: ";
					std::cin >> quant;
					if (quant != "0")
					{
						if (static_cast<int>(quant[0]) > this->inventory[static_cast<int>(choice[0] - 49)]->get_quantity())
						{
							std::cout << std::endl << "Sold " << this->inventory[static_cast<int>(choice[0] - 49)]->get_quantity()
								<< " of " << this->inventory[static_cast<int>(choice[0] - 49)]->get_name() <<
								" for " << this->inventory[static_cast<int>(choice[0] - 49)]->get_price() * this->inventory[static_cast<int>(choice[0] - 49)]->get_quantity() <<
								" golds" << std::endl;
							this->gold += this->inventory[static_cast<int>(choice[0] - 49)]->get_price() * this->inventory[static_cast<int>(choice[0] - 49)]->get_quantity();
							this->remove_elem(static_cast<int>(choice[0] - 49), this->inventory[static_cast<int>(choice[0] - 49)]->get_quantity());
						}
						else
						{
							std::cout << std::endl << "Sold " << quant << " of " << this->inventory[static_cast<int>(choice[0] - 49)]->get_name() <<
								" for " << this->inventory[static_cast<int>(choice[0] - 49)]->get_price() * static_cast<int>(quant[0] - 48) <<
								" golds" << std::endl;
							this->gold += this->inventory[static_cast<int>(choice[0] - 49)]->get_price() * static_cast<int>(quant[0] - 48);
							this->remove_elem(static_cast<int>(choice[0] - 49), static_cast<int>(quant[0] - 48));
						}
					}
					std::cout << "Press enter to continue. . .";
					getchar();
				}
				cls();
			}
			cls();
			this->show_shop_options();
		}
		else
		{
			cls();
			std::cout << "Inventory empty !" << std::endl;
			std::cout << "Press enter to continue. . .";
			getchar();
			cls();
			this->show_shop_options();
		}
	}
	else
	{
		cls();
		this->show_Town_actions();
	}


}

Item* Hero::get_right_hand()
{
	if (this->right_hand.size() > 0)
	{
		return this->right_hand.back();
	}

  return nullptr;
}


//XP//////////////////////////////////////////////////////////////

void Hero::give_xp(int amount)
{
	this->xp += amount;
}

void Hero::level_up()
{
	this->xp = 0;
	this->level++;
	cls();
	std::string choice = "0";
	while (choice == "0" || (choice != "1" && choice != "2"))
	{
		std::cout << "[LEVEL UP!]" << std::endl << std::endl;
		std::cout << "Choose which one to increase: " << std::endl;
		std::cout << "1. " << color("l_yellow") << "+1 Damage" << color("def") << std::endl;
		std::cout << "2. " << color("l_yellow") << "+1 Health Point" << color("def") << std::endl;
		std::cout << "Your choice: ";
		std::cin >> choice;
		cls();
	}
	if (choice == "1")
	{
		this->atk++;
	}
	else if (choice == "2")
	{
		this->max_hp++;
	}
	this->hp = this->max_hp;
}

int Hero::get_xp_to_lvl()
{
	return round(0.05 * (level ^ 3) + 0.8 * (level ^ 2) + 2 * level) + 15;
}

int Hero::compute_xp_needed()
{
	int actual_xp = this->xp;
	int needed = this->xp_to_levelup;
	int xp = needed - actual_xp;
	if (xp <= 0)
	{
		return 0;
	}
	else
	{
		return xp;
	}
}

//COMBAT///////////////////////////////////////////////////////////

int Hero::get_atk()
{
	int curr_atk = this->atk;
	return curr_atk;
}

int Hero::get_total_dmg()
{
	int temp_atk = 0;
	int temp_crit = 0;

	temp_atk += this->atk;
	temp_crit += this->crit_rate;
	srand((unsigned)time(0));
	if (rand() % 100 < (temp_crit))
	{
		return temp_atk * 2;
	}
	else
	{
		return temp_atk;
	}
}

int Hero::get_status_rate()
{
	return this->status_rate;
}
