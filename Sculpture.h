#ifndef SCULPTURE_H
#define SCULPTURE_H

#include "ArtWork.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>  // Needed for std::setprecision

enum class SculptureMedium {
    Ceramic,
    Stone,
    Metal,
    Mixed_Media
};

struct Dimensions3D {
    double width;
    double height;
    double depth;
};

class Sculpture : public ArtWork {
    private:
        SculptureMedium medium;
        Dimensions3D dimensions;
        double weightkg;
        static int sculptureCount; // Static variable to keep track of the number of sculptures
    public:
        Sculpture(std::string artist,
                Date created,
                Date acquired,
                std::string donatedBy,
                std::string description,
                SculptureMedium medium,
                Dimensions3D dimensions,
                double weightKg
        ): ArtWork(artist, created, acquired, donatedBy, description),
            medium(medium), dimensions(dimensions), weightkg(weightKg) {
                if(weightKg <= 0) {
                    throw std::invalid_argument("Weight must be a positive value.");
                }
                if(dimensions.width <= 0 || dimensions.height <= 0 || dimensions.depth <= 0) {
                    throw std::invalid_argument("Dimensions must be positive values.");
                }
                if(artist.empty() || donatedBy.empty() || description.empty()) {
                    throw std::invalid_argument("Artist, Donated By, and Description cannot be empty.");
                }
                if(created.getYear() > acquired.getYear()) {
                    throw std::invalid_argument("Created date cannot be after Acquired date.");
                }
                if(acquired.getYear() > 2025) {
                    throw std::invalid_argument("Acquired date cannot be in the future.");
                }
                
                sculptureCount++; // Increment the sculpture count when a new sculpture is created
            }
        ;
        static int getNumberOfSculptures(){
            return sculptureCount; // Return the current sculpture count
        }; 

        double value() const override{
            double age = created.calculateAgeInYears();
            double weightValue = weightkg/ 45.3592; // Assuming the value is based on weight
            double value = age * weightValue; // Calculate the value based on age and weight
            return value;
        }; // Override the value function to calculate the value of the sculpture
        std::string toString() const override{
            std::ostringstream oss;
            oss << "Artist: " << artist << "\n"
                    << "Created: " << created.toString() << "\n"
                    << "Acquired: " << acquired.toString() << "\n"
                    << "Donated By: " << donatedBy << "\n"
                    << "Description: " << description << "\n"
                    << "Mediam: " ;
                switch (medium)
                {
                case SculptureMedium::Ceramic:
                    oss << "Ceramic";
                    break;
                case SculptureMedium::Stone:
                    oss<< "Stone";
                    break;
                case SculptureMedium::Metal:
                    oss<< "Metal";
                    break;
                case SculptureMedium::Mixed_Media:
                    oss<< "Mixed Media";
                    break;
                }
        
                oss << "\n Dimensions(W*H*D): " << dimensions.width << "ft x " << dimensions.height << "ft x " << dimensions.depth << "ft\n"
                    << "Weight: " << weightkg << "kg\n"
                    << "Value: $" << std::fixed << std::setprecision(2) << value() << "\n";
            return oss.str(); // Return the formatted string representation of the sculpture
        
        }; // Override the toString function to provide a string representation of the sculpture
        
        
        virtual ~Sculpture() {
            // Destructor implementation (if needed)
        }
        bool operator==(const Sculpture& other) const {
            return this->value() == other.value();
        }
        
        bool operator!=(const Sculpture& other) const {
            return this->value() != other.value();
        }
        
        bool operator<(const Sculpture& other) const {
            return this->value() < other.value();
        }
        
        bool operator>(const Sculpture& other) const {
            return this->value() > other.value();
        }
        
        bool operator<=(const Sculpture& other) const {
            return this->value() <= other.value();
        }
        
        bool operator>=(const Sculpture other) const {
            return this->value() >= other.value();
        }
        
        // bool ope
        

};

#endif // "SCULPTURE_H"
