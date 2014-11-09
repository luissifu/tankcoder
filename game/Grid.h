#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "../utils/assets/Resource.h"
#include "../utils/scene/SceneManager.h"
#include "Tile.h"


class Grid {
	public:
		Grid();
		bool loadMap(std::shared_ptr<Resource> data, std::shared_ptr<SceneManager> scene);
		//
		int getWidth();
		int getHeight();
		void findPlayer(int& x, int& y);
		void findEnemy(int& x, int& y);
	private:
		void create_tile(int type, int x, int y, std::shared_ptr<SceneManager> scene);
		std::vector<Tile> tiles;
		int width;
		int height;
		int player_x;
		int player_y;
		int enemy_x;
		int enemy_y;
};
