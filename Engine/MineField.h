#pragma once
#include "Graphics.h"

class MemeField
{
private:
	class Tile
	{
	public:
		enum class State
		{
			// the following will define the class of the tiles in the mine field
			Hidden,
			Flagged,
			Revealed


		};

	public:
		void SpawnMeme();
		//this function will read if the tile has a meme and return its value, hence the const 
		bool HasMeme()const;
		void Draw(const Vei2& screenPos, Graphics& gfx)const;

	private:
		//this variable is a hidden variable and by default will invisible
		State state = State::Hidden;
		bool hasMeme = false;

	};
public:
	
	MemeField(int nMemes);
	void Draw(Graphics& gfx)const;
	RectI GetRect()const;
	Tile& TileAt(const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos)const;
private:
	static constexpr int width = 20;
	static constexpr int height = 16;

	// this next line set the number of tiles that will be set in the field
	Tile field[width * height];

};
