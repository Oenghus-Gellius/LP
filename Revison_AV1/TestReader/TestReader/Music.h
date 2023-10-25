#pragma once

#include "Reader/Include/Line.h"
#include "Reader/Include/Reader.h"

#include <iostream>
#include <cstdlib>
#include <string>

class Music
{
private:
	string nomeMusc;
	string album;
	int temp;

public:
	Music() = default;

	template<typename T>
	int addMusic(T nomeMusc, T album, T temp);

	void setNomeMusc(string nomeMusc);
	
	void setAlbum(string album);

	template<typename T>
	void setTemp(T temp);

	void createrPlaylistNome(vector<Line>playList);
};


