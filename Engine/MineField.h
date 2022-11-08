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
		void Draw(const Vei2& screenPos,bool fucked, Graphics& gfx)const;
		void Reveal();
		bool IsRevealed() const;
		void ToggleFlag();
		bool IsFlagged()const;
		void SetNeighborMemeCount(int memeCount); // This function will set he number of neighbor meme count
			

	private:
		//this variable is a hidden variable and by default will invisible
		State state = State::Hidden;
		bool hasMeme = false;
		int nNeighborMemes = -1;	//This will store the number of adjecent memes ...BY setting to -1, it lets the compiler know it is unitialized 

	};
public:
	
	MemeField(int nMemes);
	void Draw(Graphics& gfx)const;
	RectI GetRect()const;
	void OnRevealClick(const Vei2& screenPos);
	void OnFlagClick(const Vei2& screenPos);
	

private:
	Tile& TileAt(const Vei2& gridPos);
	const Tile& TileAt(const Vei2& gridPos)const;
	Vei2 ScreenToGrid(const Vei2& screenPos);
	int CountNeighborMemes(const Vei2& gridPos);
private:
	static constexpr int width = 20;
	static constexpr int height = 16;
	bool isFucked = false;

	// this next line set the number of tiles that will be set in the field
	Tile field[width * height];

};
