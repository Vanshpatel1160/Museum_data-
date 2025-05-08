#ifndef FILM_H
#define FILM_H

#include "ArtWork.h"
#include "Time.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

enum FilmGenre{
    Documentary,
    Anime,
    Animation,
    Drama,
    Comedy,
    Fantasy
};

enum FilmMedium{
    EightMM,
    SixteenMM,
    Video,
    Digital
};



class Film : public ArtWork {
    private:
        Time length;
        FilmGenre fileGenre; // Enum to represent the genre of the file
        FilmMedium fileMedium; // Enum to represent the medium of the file
        static int numberOfFiles; // Static variable to keep track of the number of file objects
    public:
        Film(const std::string& artist, const Date& created, const Date& acquired,
            const std::string& donatedBy, const std::string& description,
            const Time& length, FilmGenre filetype, FilmMedium filemedium)
            : ArtWork(artist, created, acquired, donatedBy, description), length(length), fileGenre(filetype), fileMedium(filemedium) {
                // Increment the file count when a new file object is created
                if(artist.empty() || donatedBy.empty() || description.empty()) {
                    throw std::invalid_argument("Artist, Donated By, and Description cannot be empty.");
                }
                if(created.getYear() > acquired.getYear()) {
                    throw std::invalid_argument("Created date cannot be after Acquired date.");
                }
                if(acquired.getYear() > 2025) {
                    throw std::invalid_argument("Acquired date cannot be in the future.");
                }
                numberOfFiles++;
            };
        virtual ~Film() {} // Destructor
        static int getNumberOfFiles() {
            return numberOfFiles; // Return the current file count
        }
        std::string genreToString() const {
            switch (fileGenre){
                case Documentary: return "Documentary";
                case Anime : return "Anime";
                case Animation : return "Animation";
                case Drama : return "Drama";
                case Comedy : return "Comedy";
                case Fantasy : return "Fantasy";
                default: return "Unknown Genre";
            }
        }
        std::string mediumToString() const {
            switch (fileMedium){
                case EightMM: return "8mm";
                case SixteenMM : return "16mm";
                case Video : return "Video";
                case Digital : return "Digital";
                default: return "Unknown Medium";
            }
        }
        virtual std::string toString() const override {
            std::ostringstream oss;
            oss << "Artist: " << artist << "\n"
                << "Created: " << created.toString() << "\n"
                << "Acquired: " << acquired.toString() << "\n"
                << "Donated By: " << donatedBy << "\n"
                << "Description: " << description << "\n"
                << "Length: " << length.toString() << "\n"
                << "Genre: " << genreToString() << "\n"
                << "Medium: " << mediumToString() << "\n";
                oss << "Value: $" << std::fixed << std::setprecision(2) << value() << "\n";
            return oss.str();
        }
        virtual double value() const override {
            double age =  created.calculateAgeInYears();
            double value = age * (length.convertToHours()/60); // Example calculation based on length
            return value;
        }

        bool operator==(const Film& other) const {
            return this->value() == other.value();
        }
        
        bool operator!=(const Film& other) const {
            return this->value() != other.value();
        }
        
        bool operator<(const Film& other) const {
            return this->value() < other.value();
        }
        
        bool operator>(const Film& other) const {
            return this->value() > other.value();
        }
        
        bool operator<=(const Film& other) const {
            return this->value() <= other.value();
        }
        
        bool operator>=(const Film& other) const {
            return this->value() >= other.value();
        }
        
        // bool ope

};

#endif // FILM_H