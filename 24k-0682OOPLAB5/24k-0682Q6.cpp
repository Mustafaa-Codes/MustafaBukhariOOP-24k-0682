/*
24k-0682
Syed Mustafa Bukhari
Lab 5 Question 6
*/
#include <iostream>
#include <string>

class Level {
private:
    std::string levelName;
    int difficulty;

public:
    Level(std::string name, int difficulty) : levelName(name), difficulty(difficulty) {}

    void display() const {
        std::cout << "- Level: " << levelName << " (Difficulty: " << difficulty << ")\n";
    }
};

class VideoGame {
private:
    std::string title;
    std::string genre;
    Level* levels[10];
    int levelCount;

public:
    VideoGame(std::string title, std::string genre) : title(title), genre(genre), levelCount(0) {}

    ~VideoGame() {
        for (int i = 0; i < levelCount; i++) {
            delete levels[i];
        }
    }

    void addLevel(std::string name, int difficulty) {
        if (levelCount < 10) {
            levels[levelCount++] = new Level(name, difficulty);
        }
    }

    void displayDetails() const {
        std::cout << "Game: " << title << "\nGenre: " << genre << "\nLevels:\n";
        for (int i = 0; i < levelCount; i++) {
            levels[i]->display();
        }
        std::cout << "----------------------\n";
    }
};

int main() {
    VideoGame game1("Fantasy Quest", "RPG");
    game1.addLevel("Forest of Beginnings", 1);
    game1.addLevel("Cave of Shadows", 3);
    game1.addLevel("Dragon's Lair", 5);

    game1.displayDetails();

    return 0;
}
