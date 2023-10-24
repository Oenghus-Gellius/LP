#include "Player.h"

#include <clocale>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>


int Player::printPlayList()
{

	return 0;
}

int Player::testPlayer()
{
	vector<Line> playlistFull = Reader::read("playlist.csv", Reader::SEMICOLON);
	unsigned lin = 1;

	setlocale(LC_ALL, ".utf8");


	for (Line line : playlistFull)
	{
		cout << lin++ << ". ";

		for (int position = 1; position <= 5; position = position + 4)
		{
			optional<string>titleMusic = line.getData(position);

			if (titleMusic.has_value())
			{
				cout << titleMusic.value();

				if (position == 1)
				{
					cout << " - ";
				}
				else
				{
					cout << " s" << endl;
				}
			}
		}
	}

	vector<Line> playlistPais;

	
	string album = "O Descobrimento do Brasil";

	

	for (Line line : playlistFull)
	{
		for (int  position = 2; position <+ 6; position = position + 4)
		{
			optional<string> nomeAlbum = line.getData(position);

			if (album == nomeAlbum)
			{
				playlistPais.push_back(line);
			}
		}
	}

	lin = 1;

	for (Line line : playlistPais)
	{
		cout << lin++ << ". ";

		for (int position = 1; position <= 5; position = position + 4)
		{
			optional<string>titleMusic = line.getData(position);

			if (titleMusic.has_value())
			{
				cout << titleMusic.value();

				if (position == 1)
				{
					cout << " - ";
				}
				else
				{
					cout << " s" << endl;
				}
			}
		}
	}



	printPlayList();
	return EXIT_SUCCESS;
}

int main() {
	return Player().testPlayer();
}
