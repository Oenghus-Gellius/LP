#pragma once

//Interface

#include "Reader/Include/Line.h"
#include "Reader/Include/Reader.h"
#include "Music.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Player
{
private:
	string playListNome;

	vector<Line> playListVec;

	int tamanhoList = 0;

	vector<Music> vectMusic;


public:

	Player() = default;

	//Organiza as musicas em um banco de dados e retorna objeto organizado
	vector<Line> listSourse(string playListEnter);

	void setPlayerListVec(vector<Line> listSourse);
	void setPlayListNome(string playListNome);
	void setMusics(vector<Line>playList);

	void tamanhoPlayList(vector<Line> playList);

	int getNomeMusica(string nomeMuscFinder);

	void ceatorPlayList(vector<Line>playList, string playListNome);

	optional<int> pesquisaMusica(vector<Player>playerList, string nomeMusicFinder);

	int printPlayList();

	int printPlayListProcessed();

	int testPlayer();
};

