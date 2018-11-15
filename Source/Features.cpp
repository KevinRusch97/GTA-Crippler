#include "stdafx.h"
void Features::UpdateLoop()
{
	Godmode ? godmode(true) : NULL;
	Godmode ? godmode(true) : NULL;
	Godmode ? godmode(true) : NULL;


	rainbowmenu ? Rainbowmenu(true) : NULL;

}

void spawnVehicle(char* VehicleModel)
{
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_ID()), 1);
	int Handle = PLAYER::PLAYER_PED_ID(), VehicleHash = GAMEPLAY::GET_HASH_KEY(VehicleModel);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(VehicleHash)) {
		STREAMING::REQUEST_MODEL(VehicleHash);
		while (!STREAMING::HAS_MODEL_LOADED(VehicleHash)) WAIT(0);

		int veh = VEHICLE::CREATE_VEHICLE(VehicleHash, MyCoords.x, MyCoords.y + 3.f, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(VehicleHash);
	}
}

bool Features::Godmode = false;
void Features::godmode(bool toggle) {
	if (toggle == true)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
	}
}      
bool Features::Suicice = false;
void Features::suicide(bool toggle) {
	if (toggle == true)
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), 0);
	}
	else
	{
		int maxHealth = PED::GET_PED_MAX_HEALTH(PLAYER::PLAYER_PED_ID());

		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), maxHealth);
	}
}



bool Features::UnlAmmo = false;
void Features::unlammo(bool toggle) {
	if (toggle == true)
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);
		
				
	}
	else
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}
}
int MoneyRange_ = 0;
bool Features::CashDrop1 = false;
void Features::cashDrop1(bool toggle) {
	if (toggle == true)
	{
		float angle = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, MoneyRange_) * 3.14159265359;
		float radius = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, MoneyRange_) * 5.0f;
		float x = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), true).x + radius * cos(angle);
		float y = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), true).y + radius * sin(angle);
		STREAMING::REQUEST_MODEL(0x113FD533);
		if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
		{
			OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, x, y, ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), true).z + (1), 0, 2000, 0x113FD533, 0, 1);
		}

	}
	else
	{
		//WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}
}

bool Features::CashDrop2 = false;
void Features::cashDrop2(bool toggle) {
	if (toggle == true)
	{
		Hash moneycase = $("pickup_money_security_case");
		Hash moneybag = $("prop_cash_case_01");


		float angle = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, MoneyRange_) * 3.14159265359;
		float radius = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, MoneyRange_) * 5.0f;
		float x = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), true).x + radius * cos(angle);
		float y = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), true).y + radius * sin(angle);

		STREAMING::REQUEST_MODEL(moneybag);
		if (STREAMING::HAS_MODEL_LOADED(moneybag))
		{
			OBJECT::CREATE_AMBIENT_PICKUP(0x14568F28, x, y, ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED_SCRIPT_INDEX(PLAYER::PLAYER_PED_ID()), true).z + 1.0f, 0, 2000, moneybag, 0, 1);
		}

	}
	else
	{
		//WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}
}

bool Features::SpawnFuck = false;
void Features::spawnFuck(bool toggle) {
	if (toggle == true)
	{
		WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), true);

		spawnVehicle("Dubsta3");

	}
	else
	{
		//WEAPON::SET_PED_INFINITE_AMMO_CLIP(PLAYER::PLAYER_PED_ID(), false);
	}
}


bool Features::rainbowmenu = false;
void Features::Rainbowmenu(bool toggle)
{
	if (Menu::Settings::titleRect.r > 0 && Menu::Settings::titleRect.b == 0, Menu::Settings::scroller.r > 0 && Menu::Settings::scroller.b == 0)
	{
		Menu::Settings::titleRect.r--;
		Menu::Settings::titleRect.g++;
		Menu::Settings::scroller.r--;
		Menu::Settings::scroller.g++;
	}
	if (Menu::Settings::titleRect.g > 0 && Menu::Settings::titleRect.r == 0, Menu::Settings::scroller.g > 0 && Menu::Settings::scroller.r == 0)
	{
		Menu::Settings::titleRect.g--;
		Menu::Settings::titleRect.b++;
		Menu::Settings::scroller.g--;
		Menu::Settings::scroller.b++;
	}
	if (Menu::Settings::titleRect.b > 0 && Menu::Settings::titleRect.g == 0, Menu::Settings::scroller.b > 0 && Menu::Settings::scroller.g == 0)
	{
		Menu::Settings::titleRect.r++;
		Menu::Settings::titleRect.b--;
		Menu::Settings::scroller.r++;
		Menu::Settings::scroller.b--;
	}
	(Menu::Settings::titleRect.r, Menu::Settings::titleRect.g, Menu::Settings::titleRect.b);
	(Menu::Settings::scroller.r, Menu::Settings::scroller.g, Menu::Settings::scroller.b);
}