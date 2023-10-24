#include <iostream>
#include <cstdlib>
#include <vector>
#include <optional>
#include <clocale>
#include "Reader.h"

int readerTest() {

	vector<Line>playlist = Reader::read("playlist.csv", Reader::SEMICOLON);
	unsigned l = 1;

	setlocale(LC_ALL, ".utf8");

	for (Line line : playlist) {
		cout << l++<< ". ";

		//Obtém o título (posição =1) e o tempo da música (posição =5)
		for (int position = 1; position <= 5; position += 4) {
			optional<string>titleAndTime = line.getData(position);
		
			if (titleAndTime.has_value())
				cout << titleAndTime.value();

				if (position == 1)
					cout << " - ";
				else
					cout << " s"<<endl;
		}
	}
	return EXIT_SUCCESS;
}//ReaderTest()

int main(){

	return readerTest();
}
