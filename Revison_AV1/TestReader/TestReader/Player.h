#pragma once

#include "Reader/Include/Line.h"
#include "Reader/Include/Reader.h"

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Player
{
private:
	string playList;

	string nomBandaArtista;
	string nomMusic;
	string nomAlbum;
	int positionInAlbum;
	string genero;
	int TimeMusic;
public:

	Player() = default;

	Player(vector<Line>& Playlist, string nomeList);


	int getNomBandaArtista();
	int getNomMusic();
	int getNomAlbum();
	int getPositionInAlbum();
	int getGenero();
	int getTimeMusic();

	int printPlayList();

	int testPlayer();
};

