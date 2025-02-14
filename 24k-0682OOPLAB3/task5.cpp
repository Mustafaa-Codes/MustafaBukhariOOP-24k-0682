/*
24k-0682
Syed Mustafa Bukhari
OOP Lab 3
*/
#include <iostream>
#include <string>

using namespace std;

class MusicPlayer {
private:
    string playlist[10];
    string currentlyPlaying;
    int totalSongs;

public:
    MusicPlayer() : totalSongs(0), currentlyPlaying("No song playing") {}

    void addSong(const string& song) {
        if (totalSongs < 10) {
            playlist[totalSongs++] = song;
            cout << "Added song: " << song << endl;
        } else {
            cout << "Playlist is full! Cannot add more songs.\n";
        }
    }

    void removeSong(const string& song) {
        bool found = false;
        for (int i = 0; i < totalSongs; i++) {
            if (playlist[i] == song) {
                found = true;
                for (int j = i; j < totalSongs - 1; j++) {
                    playlist[j] = playlist[j + 1];
                }
                totalSongs--;
                cout << "Removed song: " << song << endl;
                if (currentlyPlaying == song) {
                    currentlyPlaying = "No song playing";
                }
                break;
            }
        }
        if (!found) {
            cout << "Song \"" << song << "\" not found in playlist.\n";
        }
    }

    void playSong(const string& song) {
        bool found = false;
        for (int i = 0; i < totalSongs; i++) {
            if (playlist[i] == song) {
                currentlyPlaying = song;
                cout << "Now playing: " << song << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Song \"" << song << "\" is not in the playlist.\n";
        }
    }

    void displayPlaylist() const {
        cout << "\nPlaylist:\n";
        if (totalSongs == 0) {
            cout << "No songs in the playlist.\n";
        } else {
            for (int i = 0; i < totalSongs; i++) {
                cout << i + 1 << ". " << playlist[i] << endl;
            }
        }
    }

    void currentlyPlayingSong() const {
        cout << "\nCurrently Playing: " << currentlyPlaying << endl;
    }
};

int main() {
    MusicPlayer imransPlayer;

    imransPlayer.addSong("Shape of You");
    imransPlayer.addSong("Perfect");
    imransPlayer.addSong("Senorita");

    imransPlayer.displayPlaylist();

    imransPlayer.playSong("Perfect");
    imransPlayer.currentlyPlayingSong();

    imransPlayer.removeSong("Shape of You");
    imransPlayer.displayPlaylist();

    imransPlayer.playSong("Shape of You");

    return 0;
}
