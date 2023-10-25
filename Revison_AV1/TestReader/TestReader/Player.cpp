#include "Player.h"

#include "Music.h"

#include <clocale>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>


vector<Line> Player::listSourse(string playListEnter)
{
	vector<Line> sourseList = Reader::read(playListEnter, Reader::SEMICOLON);

	return sourseList;
}

void Player::setPlayerListVec(vector<Line> listSourse)
{
	this->playListVec = listSourse;
}

void Player::setPlayListNome(string playListNome)
{
	this->playListNome = playListNome;
}

void Player::setMusics(vector<Line> playList) // <-----PAREI AQUI
{
	vector<Music> musicList = Music::createrPlaylistNome(playList);

	this->vectMusic = musicList;
}

void Player::tamanhoPlayList(vector<Line> playList)
{
	this->tamanhoList = playList.size();
}

int Player::getNomeMusica(string nomeMuscFinder)
{
	return 0;
}

void Player::ceatorPlayList(vector<Line> playList, string playListNome)
{
	setPlayListNome(playListNome);

	setPlayerListVec(playList);

	setMusics(playList);

	tamanhoPlayList(playList);
}

optional<int> Player::pesquisaMusica(vector<Player> playerList, string nomeMusicFinder)
{

	return optional<int>();
}

int Player::printPlayList()
{
	setlocale(LC_ALL, ".utf8");

	unsigned lin = 1;

	for (Line line : playListVec)
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

	return 0;
}

int Player::printPlayListProcessed()
{
	setlocale(LC_ALL, ".utf8");

	unsigned lin = 1;

	cout << "Nome Musica\t\t" << "Album\t\t" << "Tempo" << endl;

	for (Music musica : vectMusic)
	{
		cout << lin++ << ". ";

		for (int position = 1; position <= 5; position++)
		{
			//optional<string>nome = musica.getDataMusic(2);
			//optional<string>album = musica.getDataMusic(3);
			//optional<string>temp = musica.getDataMusic(6);

			optional<string>token = musica.getDataMusic(position);

			if (token.has_value())
			{
				cout << token.value() << "\t\t\t";
			}
		}
		cout << "\n" << endl;
		//cout << "Nome Musica\t\t\t" << "Album\t\t" << "Tempo" << endl;
	}

	return 0;
}

int Player::testPlayer()
{
	string nomeSoucer = "playlist.csv";

	string nomePlayListA = "SOURCE";

	vector<Line> vecSourse = listSourse(nomeSoucer);

	Player playerListSourse;

	playerListSourse.ceatorPlayList(vecSourse, nomePlayListA);

	playerListSourse.printPlayList();

	playerListSourse.printPlayListProcessed();



	string pesquisaMusic = "Faroeste Caboclo";

	//string album = "O Descobrimento do Brasil";
	return EXIT_SUCCESS;
}

int main() {
	return Player().testPlayer();
}
