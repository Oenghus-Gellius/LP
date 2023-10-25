#include "Music.h"

#include "Player.h"

#include <clocale>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>


template<typename T>
inline int Music::addMusic(T nomeMusc, T album, T temp)
{
	setNomeMusc(nomeMusc);
	setAlbum(album);
	setTemp(temp);

	return 1;
}

void Music::setNomeMusc(string nomeMusc)
{
	this->nomeMusc = nomeMusc;
}

void Music::setAlbum(string album)
{
	this->album = album;
}

template<typename T>
void Music::setTemp(T temp)
{
	this->temp = temp;
}

optional<string> Music::getDataMusic(int position)// <Fazer
{
	if (position >= 0 && position < music.size())
	{
		return music[position];
	}
	return nullopt;
}

vector<Music> Music::createrPlaylistNome(vector<Line>playList)
{
	vector<Music> musicList;

	for (Line line : playList)
	{
		Music music;

		for (int position = 1; position < 6; position++)
		{
			optional<string> infoMusic = line.getData(position);
			if (infoMusic.has_value())
			{
				string token = infoMusic.value();
				switch (position)
				{
				case 1:
					music.setNomeMusc(token);
					break;
				case 2:
					music.setAlbum(token);
					break;
				case 3:
					
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					music.setTemp(token);
					break;
				default:
					break;
				}
			}
		}
		// Adicionar a música ao vetor vectMusic
		musicList.push_back(music);
	}
	return musicList;
}
