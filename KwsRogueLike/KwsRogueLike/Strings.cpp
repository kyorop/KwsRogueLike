#include "Strings.h"
#include <DxLib.h>

using namespace std;

Strings::Strings()
{
	/* �኱����
	//������ւ�Astring�g���Ă��܂��������肵�Ȃ����ȁH
	char s_floor[sizeof(floor)]; //�K�w�f�[�^���Ăǂ��ɒu�����H
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
	*/
}

void Strings::DisplayPlayerData(int floor,PlayerBase* player)
{
	char s_floor[sizeof(floor)]; //�K�w�f�[�^���Ăǂ��ɒu�����H
	char s_hp[sizeof(player->GetHp())];
	char s_level[sizeof(player->GetLevel())];
	char s_gold[sizeof(player->GetGold())];
	sprintf_s(s_floor, "%d", floor);
	sprintf_s(s_hp, "%d", player->GetHp());
	sprintf_s(s_level, "%d", player->GetLevel());
	sprintf_s(s_gold, "%d", player->GetGold());
	DrawFormatString(100, 10, GetColor(255, 255, 255), "%s�e",s_floor);
	DrawFormatString(200, 10, GetColor(255, 255, 255), "�g�o%s",s_hp);
	DrawFormatString(300, 10, GetColor(255, 255, 255), "�k���D%s",s_level);
	DrawFormatString(400, 10, GetColor(255, 255, 255), "%s�f",s_gold);
}

Strings::~Strings()
{
}
