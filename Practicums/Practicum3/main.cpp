#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_STR_LEN = 30;

char genre[148][32] = {"Blues", "Classic Rock", "Country", "Dance",
                       "Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal",
                       "New Age", "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae", "Rock",
                       "Techno", "Industrial", "Alternative", "Ska", "Death Metal",
                       "Pranks", "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop",
                       "Vocal", "Jazz+Funk", "Fusion", "Trance", "Classical",
                       "Instrumental", "Acid", "House", "Game", "Sound Clip", "Gospel",
                       "Noise", "Alternative Rock", "Bass", "Soul", "Punk", "Space",
                       "Meditative", "Instrumental Pop", "Instrumental Rock", "Ethnic",
                       "Gothic", "Darkwave", "Techno-Industrial", "Electronic", "Pop-Folk",
                       "Eurodance", "Dream", "Southern Rock", "Comedy", "Cult", "Gangsta",
                       "Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American",
                       "Cabaret", "New Wave", "Psychadelic", "Rave", "Showtunes",
                       "Trailer", "Lo-Fi", "Tribal", "Acid Punk", "Acid Jazz", "Polka",
                       "Retro", "Musical", "Rock & Roll", "Hard Rock", "Folk", "Folk-Rock",
                       "National Folk", "Swing", "Fast Fusion", "Bebob", "Latin",
                       "Revival", "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock",
                       "Progressive Rock", "Psychedelic Rock", "Symphonic Rock",
                       "Slow Rock", "Big Band", "Chorus", "Easy Listening", "Acoustic",
                       "Humour", "Speech", "Chanson", "Opera", "Chamber Music", "Sonata",
                       "Symphony", "Booty Bass", "Primus", "Porn Groove", "Satire",
                       "Slow Jam", "Club", "Tango", "Samba", "Folklore", "Ballad",
                       "Power Ballad", "Rhythmic Soul", "Freestyle", "Duet", "Punk Rock",
                       "Drum Solo", "Acapella", "Euro-House", "Dance Hall", "Goa",
                       "Drum & Bass", "Club-House", "Hardcore", "Terror", "Indie",
                       "BritPop", "Negerpunk", "Polsk Pumk", "Beat",
                       "Christian Gangsta Rap", "Heavy Metal", "Black Metal", "Crossover",
                       "Contemporary Christian", "Christian Rock", "Merengue", "Salsa",
                       "Thrash Metal", "Anime", "JPop", "Synthpop"};

struct SongData
{
    string header;
    string title;
    string artist;
    string album;
    int year;
    string comment;
    int trackNumber;
    string genre;
};

void FillStruct(SongData &, string);
void ReadHeader(SongData &, ifstream &);
void ReadTitle(SongData &, ifstream &);
void ReadArtist(SongData &, ifstream &);
void ReadAlbum(SongData &, ifstream &);
void ReadYear(SongData &, ifstream &);
void ReadComment(SongData &, ifstream &);
void ReadTrackNumber(SongData &, ifstream &);
void ReadGenre(SongData &, ifstream &);
bool ExtensionCheck(string);

int main()
{
    SongData song;
    string file;
    cin >> file;
    bool correctExtension = ExtensionCheck(file);

    // if(ExtensionCheck(file) == 1)
    // {
    //     FillStruct(song, file);
    // }
    // else
    // {
    //     cout << "Incorrect file extension... Terminating Program";
    // }
    FillStruct(song, file);

    return 0;
}

void ReadHeader(SongData &songData, ifstream &fin)
{
    songData.header = "";
    for (int i = 0; i < 3; i++)
    {
        char c;
        fin >> c;
        songData.header += c;
    }
    //cout << "Header: " << songData.header << endl;
}

void ReadTitle(SongData &songData, ifstream &fin)
{
    songData.title = "";
    char c;
    fin >> c;
    while (c != 0)
    {
        songData.title += c;
        fin >> c;
    }
    fin.seekg(MAX_STR_LEN - (songData.title.length() + 1), fin.cur);
    cout << "Title: " << songData.title << endl;
}

void ReadArtist(SongData &songData, ifstream &fin)
{
    songData.artist = "";
    char c;
    fin >> c;
    while (c != 0)
    {
        songData.artist += c;
        fin >> c;
    }
    fin.seekg(MAX_STR_LEN - (songData.artist.length() + 1), fin.cur);
    cout << "Artist: " << songData.artist << endl;
}

void ReadAlbum(SongData &songData, ifstream &fin)
{
    songData.album = "";
    char c;
    fin >> c;
    while (c != 0)
    {
        songData.album += c;
        fin >> c;
    }
    fin.seekg(MAX_STR_LEN - (songData.album.length() + 1), fin.cur);
    cout << "Album: " << songData.album << endl;
}

void ReadYear(SongData &songData, ifstream &fin)
{
    int year;
    fin >> year;
    songData.year = year;
    cout << "Year: " << songData.year << endl;
}

void ReadComment(SongData &songData, ifstream &fin)
{
    songData.comment = "";
    char c;
    fin >> c;
    while (c != 0)
    {
        songData.album += c;
        fin >> c;
    }
    fin.seekg(MAX_STR_LEN - (songData.album.length()), fin.cur);
    cout << "Comment: " << songData.comment << endl;
}

void ReadTrackNumber(SongData &songData, ifstream &fin)
{
    char c;
    fin >> c;
    songData.trackNumber = (int)c;
    cout << "TrackNumber: " << songData.trackNumber << endl;
}

void ReadGenre(SongData &songData, ifstream &fin)
{
    char c;
    fin >> c;
    string musicGenre = "";
    for (int i = 0; genre[c][i] != '\0'; i++)
    {
        musicGenre += genre[c][i];
    }
    songData.genre = musicGenre;
    cout << "Genre: " << songData.genre << endl;
}

void FillStruct(SongData &song, string file)
{
    ifstream fin;
    fin.open(file.c_str());
    fin.seekg(-128, fin.end);

    ReadHeader(song, fin);
    ReadTitle(song, fin);
    ReadArtist(song, fin);
    ReadAlbum(song, fin);
    ReadYear(song, fin);
    ReadComment(song, fin);
    ReadTrackNumber(song, fin);
    ReadGenre(song, fin);
    // cout << song.header << endl;
    // cout << song.title << endl;
    // cout << song.artist << endl;
    // cout << song.album << endl;
    // cout << song.year << endl;
    // cout << song.comment << endl;
    // cout << song.trackNumber << endl;
    // cout << song.genre << endl;
}

bool ExtensionCheck(string file)
{
    string ext = ".mp3";
    for(int i = file.length() - 4, j = 0; i < file.length(); i++, j++)
    {
        //cout << "this is i: " << file[i] << " " << "This is j: " << ext[j] << endl;
        if(ext[j] != file[i])
        {
            return 0;
        }
    }
    return 1;
}
