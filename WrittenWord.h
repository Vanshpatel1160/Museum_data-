#ifndef WRITTENWORD_H
#define WRITTENWORD_H

#include "ArtWork.h"
#include <string>
#include <iostream>
#include <sstream>

enum genreBook{
    Novel,
    Biography,
    Anthology,
    IIIusrated,
    Autobiography,
    Nonfiction,
    Poetry
};

class WrittenWord : public ArtWork {
    private:
        int numPages;
        genreBook bookGenre; // Enum to represent the genre of the book
        static int numberOfWrittenWordItems; // Static variable to keep track of the number of WrittenWord objects
    public:
        WrittenWord(const std::string& artist, const Date& created, const Date& acquired,
            const std::string& donatedBy, const std::string& description,
            int NumPages, genreBook booktype) : ArtWork(artist, created, acquired, donatedBy, description), numPages(NumPages), bookGenre(booktype) {
                // Increment the written word count when a new WrittenWord object is created
                if(artist.empty() || donatedBy.empty() || description.empty()) {
                    throw std::invalid_argument("Artist, Donated By, and Description cannot be empty.");
                }
                if(created.getYear() > acquired.getYear()) {
                    throw std::invalid_argument("Created date cannot be after Acquired date.");
                }
                if(acquired.getYear() > 2025) {
                    throw std::invalid_argument("Acquired date cannot be in the future.");
                }
                if(NumPages <= 0) {
                    throw std::invalid_argument("Number of pages must be a positive value.");
                }
               
                numberOfWrittenWordItems++;
            };

        virtual ~WrittenWord() {} // Destructor
        
        std::string genreToString() const {
            switch (bookGenre){
                case Novel: return "Novel";
                case Biography : return "Biography";
                case Anthology : return "Anthology";
                case IIIusrated : return "IIIusrated";
                case Autobiography : return "Autobiography";
                case Nonfiction : return "Nonfiction";
                case Poetry : return "Poetry";
                default: return "Unknown Genre";
            }
        }

        virtual std::string toString() const override {
            std::ostringstream oss;
            oss << "Artist: " << artist << "\n"
                << "Created: " << created.toString() << "\n"
                << "Acquired: " << acquired.toString() << "\n"
                << "Donated By: " << donatedBy << "\n"
                << "Description: " << description << "\n"
                << "Number of Pages: " << numPages << "\n"
                << "Genre: " << genreToString();
                oss << "Value: $" << std::fixed << std::setprecision(2) << value() << "\n";
            return oss.str();
        }

        virtual double value() const override {
            double age = created.calculateAgeInYears();
            double value = age * (numPages / 100.0); // Example calculation based on number of pages
            return value;
        }

        static int getNumberOfWrittenWordItems() {
            return numberOfWrittenWordItems; // Return the current written word count
        }
        bool operator==(const WrittenWord& other) const {
            return this->value() == other.value();
        }
        
        bool operator!=(const WrittenWord& other) const {
            return this->value() != other.value();
        }
        
        bool operator<(const WrittenWord& other) const {
            return this->value() < other.value();
        }
        
        bool operator>(const WrittenWord& other) const {
            return this->value() > other.value();
        }
        
        bool operator<=(const WrittenWord& other) const {
            return this->value() <= other.value();
        }
        
        bool operator>=(const WrittenWord& other) const {
            return this->value() >= other.value();
        }
        
        // bool ope
        

};
#endif // WRITTENWORD_H