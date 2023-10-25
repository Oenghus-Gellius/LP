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

void Music::createrPlaylistNome(vector<Line> playList)
{
	for (Line line : playList)
	{
		for (int position = 1; position < 6; position++)
		{
			optional<string> infoMusic = line.getData(position);
			if (infoMusic.has_value())
			{
				string token = infoMusic.value();
				switch (position)
				{
				case 1:
					break;
				case 2:
					setNomeMusc(token);
					break;
				case 3:
					setAlbum(token);
					break;
				case 4:
					break;
				case 5:
					break;
				case 6:
					setTemp(token);
					break;
				default:
					break;
				}
			}
		}
		// Criar um objeto Music com as informações extraídas
		Music music;
		music.addMusic(nomeMusc, album, temp);

		// Adicionar a música ao vetor vectMusic
		vectMusic.push_back(music);
	}
}
