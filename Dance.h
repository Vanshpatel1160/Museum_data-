#ifndef DANCE_H
#define DANCE_H

#include "ArtWork.h"
#include "Time.h"
#include <string>
#include <iostream>

class Dance : public ArtWork {
    private:
        std::string performedBy;   
        Time Length; // Time object to represent the length of the dance
        static int numberOfDanceItems; // Static variable to keep track of the number of Dance objects
    public:
        Dance(const std::string& artist, const Date& created, const Date& acquired,
            const std::string& donatedBy, const std::string& description,
            const std::string& performedBy,const Time& Lenght):
            ArtWork(artist, created, acquired, donatedBy, description) , performedBy(performedBy), Length(Lenght) {
                // Increment the dance count when a new Dance object is created
                if(artist.empty() || donatedBy.empty() || description.empty()) {
                    throw std::invalid_argument("Artist, Donated By, and Description cannot be empty.");
                }
                if(created.getYear() > acquired.getYear()) {
                    throw std::invalid_argument("Created date cannot be after Acquired date.");
                }
                if(acquired.getYear() > 2025) {
                    throw std::invalid_argument("Acquired date cannot be in the future.");
                }
                if(Length.convertToHours() <= 0) {
                    throw std::invalid_argument("Length must be a positive value.");
                }
                if(performedBy.empty()) {
                    throw std::invalid_argument("Performed By cannot be empty.");
                }
                numberOfDanceItems++;

            };
        virtual ~Dance() {} // Destructor

        virtual std::string toString() const override {
            std::ostringstream oss;
            oss << "Artist: " << artist << "\n"
                << "Created: " << created.toString() << "\n"
                << "Acquired: " << acquired.toString() << "\n"
                << "Donated By: " << donatedBy << "\n"
                << "Description: " << description << "\n"
                << "Performed By: " << performedBy << "\n"
                << "Length: " << Length.toString() << "\n";
                oss << "Value: $" << std::fixed << std::setprecision(2) << value() << "\n";
            return oss.str();
        }
        virtual double value() const override {
            double age = created.calculateAgeInYears();
            double value = age * (Length.convertToHours()/60);
            return value;
        }

        static int getNumberOfDanceItems() {
            return numberOfDanceItems; // Return the current dance count
        }

        bool operator==(const Dance& other) const {
            return this->value() == other.value();
        }
        
        bool operator!=(const Dance& other) const {
            return this->value() != other.value();
        }
        
        bool operator<(const Dance& other) const {
            return this->value() < other.value();
        }
        
        bool operator>(const Dance& other) const {
            return this->value() > other.value();
        }
        
        bool operator<=(const Dance& other) const {
            return this->value() <= other.value();
        }
        
        bool operator>=(const Dance other) const {
            return this->value() >= other.value();
        }
        
    

        


};
#endif // DANCE_H