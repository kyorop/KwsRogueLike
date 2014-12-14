#pragma once
#include <memory>


class CharacterBase;

class GameManager
{
public:
	void Initialize();
	void Main();
	void Finalize();

	std::shared_ptr<CharacterBase> GetPlayer()
	{
		return player;
	}

private:
	std::shared_ptr<CharacterBase> player;
};
