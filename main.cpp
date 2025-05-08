#include "Painting.h"
#include "Sculpture.h"
#include "Dance.h"
#include "Film.h"
#include "Music.h"
#include "WrittenWord.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int Dance::numberOfDanceItems = 0; // Initialize the static variable
int Film::numberOfFiles = 0;       // Initialize the static variable
int Music::numberofMusicItems = 0; // Initialize the static variable
int Painting::numberOfPaintings = 0;
int Sculpture::sculptureCount = 0;
int WrittenWord::numberOfWrittenWordItems = 0;

template <typename T>
T* FindMaxValue(T* arry[], int size) {
    T* max = arry[0];
    for (int i = 1; i < size; ++i) {
        if (arry[i]->value() > max->value()) {
            max = arry[i];
        }
    }
    return max;
}

template <typename T>
T* FindMinValue(T* arry[], int size) {
    T* min = arry[0];
    for (int i = 1; i < size; ++i) {
        if (arry[i]->value() < min->value()) {
            min = arry[i];
        }
    }
    return min;
}

int main() {
    Date c(5, 15, 1990), a(3, 22, 2010);
    Time t(2, 45);

    std::vector<ArtWork*> museum;

    museum.push_back(new Painting("Monet", c, a, "Louvre", "Water Lilies", PaintingMedium::OIL, 4.0, 3.0));
    museum.push_back(new Sculpture("Rodin", c, a, "Paris Museum", "The Thinker", SculptureMedium::Metal, {2.0, 2.0, 1.0}, 800.0));
    museum.push_back(new Dance("Anna Pavlova", c, a, "Ballet Company", "The Dying Swan", "Solo", t));
    museum.push_back(new Film("James Cameron", c, a, "Universal", "Avatar", t, FilmGenre::Fantasy, FilmMedium::Digital));
    museum.push_back(new Music("Mozart", c, a, "Opera House", "Requiem", "Orchestra", t, recordingMedium::MusicDigital, genreMusic::Classical));
    museum.push_back(new WrittenWord("Tolkien", c, a, "Library", "The Hobbit",310, genreBook::Novel));

    std::cout << "===== ALL ARTWORKS =====\n";
    for (auto* art : museum) {
        std::cout << *art << "\n";
    }

    std::ofstream outFile("alternate_inventory.txt");
    if (!outFile) {
        std::cerr << "Error writing to file.\n";
    } else {
        for (auto* art : museum) {
            outFile << *art << "\n";
        }
        outFile.close();
        std::cout << "Inventory written to 'alternate_inventory.txt'\n";
    }


    std::cout << "===== COMPARISON TEST =====\n";
    Painting p1("Van Gogh", c, a, "Gallery", "Irises", PaintingMedium::OIL, 3.0, 3.0);
    Painting p2("Da Vinci", c, a, "Gallery", "Last Supper", PaintingMedium::OIL, 5.0, 4.0);
    std::cout << (p1 < p2 ? "p2 is more valuable.\n" : "p1 is more valuable.\n");

    std::cout << "===== MIN/MAX TEST =====\n";
    ArtWork* max = FindMaxValue(&museum[0], museum.size());
    ArtWork* min = FindMinValue(&museum[0], museum.size());
    std::cout << "Most Valuable:\n" << *max << "\n";
    std::cout << "Least Valuable:\n" << *min << "\n";

    std::cout << "===== EXCEPTION TEST =====\n";
    try {
        Painting bad("", c, a, "Gallery", "", PaintingMedium::OIL, 0, 0);
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "===== STATIC COUNT TEST =====\n";
    std::cout << "Number of Paintings: " << Painting::getNumberOfPaintings() << "\n";
    std::cout << "Number of Sculptures: " << Sculpture::getNumberOfSculptures() << "\n";
    std::cout << "Number of Dance Items: " << Dance::getNumberOfDanceItems() << "\n";
    std::cout << "Number of Film Items: " << Film::getNumberOfFiles() << "\n";
    std::cout << "Number of Music Items: " << Music::getNumberOfMusicItems() << "\n";
    std::cout << "Number of Written Word Items: " << WrittenWord::getNumberOfWrittenWordItems() << "\n";
    
    


    for (auto* art : museum)
        delete art;

    return 0;
}
