#ifndef MUSIC_H
#define MUSIC_H
#include "ArtWork.h"
#include "Time.h"

#include <string>
#include <iostream>
#include <sstream> // Include sstream for string stream operations
#include <iomanip> // Include iomanip for std::setprecision

enum recordingMedium{
    Tape,
    MusicDigital,
    Paper
};

enum genreMusic {
    Classical,
    Baroque,
    Folk,
    Traditional,
    Rock,
    Metal,
    HipHop,
    Broadway,
    Musical,
    Symphony,
    Opera

};

class Music :public ArtWork{
    private:
        std::string performedBy;
        Time Length; 
        recordingMedium musicMedium;
        genreMusic musicGenre; 
        static int numberofMusicItems; 
    public:
        Music(const std::string& artist, const Date& created, const Date& acquired,
            const std::string& donatedBy, const std::string& description,
            const std::string& performedBy, const Time& Length, recordingMedium musicmedium, genreMusic musicgenre)
            : ArtWork(artist, created, acquired, donatedBy, description), performedBy(performedBy), Length(Length), musicMedium(musicmedium), musicGenre(musicgenre) {
                // Increment the music count when a new Music object is created
                if(artist.empty() || donatedBy.empty() || description.empty()) {
                    throw std::invalid_argument("Artist, Donated By, and Description cannot be empty.");
                }
                if(created.getYear() > acquired.getYear()) {
                    throw std::invalid_argument("Created date cannot be after Acquired date.");
                }
                if(acquired.getYear() > 2025) {
                    throw std::invalid_argument("Acquired date cannot be in the future.");
                }
                numberofMusicItems++;
            };
        virtual ~Music() {} // Destructor
        static int getNumberOfMusicItems() {
            return numberofMusicItems; // Return the current music count
        }

        std::string genreMusictostring() const {
            switch (musicGenre)  {
                case Classical: return "Classical";
                case Baroque : return "Baroque";
                case Folk : return "Folk";
                case Traditional : return "Traditional";
                case Rock : return "Rock";
                case Metal : return "metal";
                case HipHop : return "HipHop";
                case Broadway : return "Broadway";
                case Musical : return "Musical";
                case Symphony : return "Symphony";
                case Opera : return "Opera";

                default: return "Unknown Genre";
            }
        }
        
        std::string mediumToString() const {
            switch (musicMedium){
                case Tape: return "Tape";
                case MusicDigital : return "MusicDigital";
                case Paper : return "paper";
                default: return "Unknown Medium";
            }
        }

        std::string toString() const override {
            std::ostringstream oss;
            oss << "Artist: " << artist << "\n"
                << "Created: " << created.toString() << "\n"
                << "Acquired: " << acquired.toString() << "\n"
                << "Donated By: " << donatedBy << "\n"
                << "Description: " << description << "\n"
                << "Performed By: " << performedBy << "\n"
                << "Length: " << Length.toString() << "\n"
                << "Medium: " << mediumToString() << "\n"
                << "Genre: " << genreMusictostring() << "\n";
                oss << "Value: $" << std::fixed << std::setprecision(2) << value() << "\n";
            return oss.str();
        }
        double value() const override {
            double age = created.calculateAgeInYears();
            double lenghtInHours = Length.convertToHours();
            double value ;
            value = age * (lenghtInHours *60); // Example calculation
            return value; // Return the calculated value
        }
        bool operator==(const Music& other) const {
            return this->value() == other.value();
        }
        
        bool operator!=(const Music& other) const {
            return this->value() != other.value();
        }
        
        bool operator<(const Music& other) const {
            return this->value() < other.value();
        }
        
        bool operator>(const Music& other) const {
            return this->value() > other.value();
        }
        
        bool operator<=(const Music& other) const {
            return this->value() <= other.value();
        }
        
        bool operator>=(const Music& other) const {
            return this->value() >= other.value();
        }
        
        // bool ope

};

#endif // MUSIC_H