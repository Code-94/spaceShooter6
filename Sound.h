#pragma once
#include <SFML/Audio.hpp>
#include <string_view>


class Sound {
	sf::SoundBuffer buffer_;
	

public:
	
	void SoundLoadPlay(sf::SoundBuffer,std::string_view);
	
};