#pragma once

//Interface

#include "Reader/Include/Line.h"
#include "Reader/Include/Reader.h"

#include <iostream>
#include <cstdlib>
#include <string>

class Music
{
private:
	vector<string>music;

	string nomeMusc;
	string album;
	string temp;

public:
	Music() = default;

	template<typename T>
	int addMusic(T nomeMusc, T album, T temp);

	//void setVectMusic();

	void setNomeMusc(string nomeMusc);
	
	void setAlbum(string album);

	template<typename T>
	void setTemp(T temp);

	optional<string>getDataMusic(int position); // <Fazer

	vector<Music> createrPlaylistNome(vector<Line>playList);
};


