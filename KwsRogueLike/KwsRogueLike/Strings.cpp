#include "Strings.h"
#include <DxLib.h>
#include "playerbase.h"
#include "Image.h"

using namespace std;

void Strings::Draw(ImageManager* manager)
{
	DisplayPlayerData();
}

/*
Strings::Strings()
{
	 若干迷走
	//ここらへん、string使ってうまく書けたりしないかな？
	char s_floor[sizeof(floor)]; //階層データってどこに置こう？
	char s_hp[sizeof(player->GetHp())];
	char s_level[sizeof(player-> GetLevel())];
	char s_gold[sizeof(player->GetGold())];
	sprintf_s(s_floor, "%d", floor);
	sprintf_s(s_hp, "%d", player->GetHp());
	sprintf_s(s_level, "%d", player->GetLevel());
	sprintf_s(s_gold, "%d", player->GetGold());
	DrawFormatString(50, 10, GetColor(255, 255, 255), s_floor);
	DrawFormatString(100, 10, GetColor(255, 255, 255), s_hp);
	DrawFormatString(150, 10, GetColor(255, 255, 255), s_level);
	DrawFormatString(200, 10, GetColor(255, 255, 255), s_gold);
}
*/

Strings::Strings(int currentFloor, PlayerBase* player)
	:currentFloor(currentFloor),
	player(player)
{
}

void Strings::DisplayPlayerData()
{
//	char s_floor[sizeof(floor)]; //階層データってどこに置こう？
//	char s_hp[sizeof(player->GetHp())];
//	char s_level[sizeof(player->GetLevel())];
//	char s_gold[sizeof(player->GetGold())];
//	sprintf_s(s_floor, "%d", floor);
//	sprintf_s(s_hp, "%d", player->GetHp());
//	sprintf_s(s_level, "%d", player->GetLevel());
//	sprintf_s(s_gold, "%d", player->GetGold());
//	DrawFormatString(100, 10, GetColor(255, 255, 255), "%sＦ",s_floor);
//	DrawFormatString(200, 10, GetColor(255, 255, 255), "ＨＰ%s",s_hp);
//	DrawFormatString(300, 10, GetColor(255, 255, 255), "Ｌｖ．%s",s_level);
//	DrawFormatString(400, 10, GetColor(255, 255, 255), "%sＧ",s_gold);
	
	//string使ってやってみました
	s_floor = std::to_string(currentFloor);
	s_hp = std::to_string(player->GetHp());
	s_level = std::to_string(player->GetLevel());
	s_gold = std::to_string(player->GetGold());

	int black = GetColor(0, 0, 0);
	DrawFormatString(100, 10, black, "%sＦ", s_floor.data());
	DrawFormatString(200, 10, black, "ＨＰ%s", s_hp.data());
	DrawFormatString(300, 10, black, "Ｌｖ．%s", s_level.data());
	DrawFormatString(400, 10, black, "%sＧ", s_gold.data());
}

