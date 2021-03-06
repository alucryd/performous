#pragma once

#include "animvalue.hh"
#include "cachemap.hh"
#include "screen.hh"
#include "textinput.hh"

class Song;
class Audio;
class Video;
class Players;
class Surface;
class Database;
class ThemeSongs;
class LayoutSinger;

/** Player hiscore addition screen.
  Database is passed as argument, but only the players is stored
  and used everywhere.
 */
class ScreenPlayers : public Screen {
  public:
	/// constructor
	ScreenPlayers(std::string const& name, Audio& audio, Database& database);
	void enter();
	void exit();
	void manageEvent(SDL_Event event);
	void manageEvent(input::NavEvent const& event);
	void draw();

	void setSong (std::shared_ptr<Song> song_)
	{
		m_song = song_;
	}

  private:
	Audio& m_audio;
	Database& m_database;
	Players& m_players;
	std::shared_ptr<Song> m_song; /// Pointer to the current song
	std::unique_ptr<Surface> m_songbg;
	std::unique_ptr<Video> m_video;
	std::unique_ptr<ThemeSongs> theme;
	std::string m_playing;
	std::string m_playReq;
	AnimValue m_playTimer;
	AnimValue m_quitTimer;
	TextInput m_search;
	std::unique_ptr<Surface> m_emptyCover;
	Cachemap<fs::path, Surface> m_covers;
	std::unique_ptr<LayoutSinger> m_layout_singer;
	bool keyPressed = false;
};
