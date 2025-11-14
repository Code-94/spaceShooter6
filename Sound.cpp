#include "Sound.h"


void Sound::SoundLoadPlay(sf::SoundBuffer buff, std::string_view pathFile)
{
	buff.loadFromFile(pathFile);
	sf::Sound boum(buff);
	boum.play();

}



