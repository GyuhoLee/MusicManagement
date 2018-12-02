#ifndef _BASE_H
#define _BASE_H

#include <conio.h>
#include <atlstr.h>
class MusicList;
class GenreList;
class ArtistList;
class AlbumList;

class Base
{
public:
	static MusicList m_List;				///< music list.
	static GenreList m_gList;				///< genre list.
	static ArtistList m_atList;				///< artist list.
	static AlbumList m_abList;				///< album list.
};

#endif