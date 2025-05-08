#ifndef PAINTING_H
#define PAINTING_H

#include "ArtWork.h"
#include "Date.h"
#include <string>
#include <iostream>
#include <iomanip>  // Needed for std::setprecision
#include <sstream>  // Needed for std::ostringstream


enum class PaintingMedium {
    OIL,
    ACRYLIC,
    MIXEDMEDIA,
    WATERCOLOR    
};

class Painting : public ArtWork {
    private:
        PaintingMedium medium;
        double Width;
        double Height;
        static int  numberOfPaintings; // Static variable to keep track of the number of paintings
    public:
        Painting(const std:: string& artist, const Date& created, const Date& acquired, const std:: string& donatedBy, const std:: string& description, PaintingMedium mediamm, double width, double height)
        : ArtWork(artist, created, acquired, donatedBy, description), medium(mediamm), Width(width), Height(height){
                // Increment the painting count when a new painting is created
            numberOfPaintings++;

            if(width <= 0 || height <= 0) {
                throw std::invalid_argument("Width and Height must be positive values.");
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
        };
             // Increment the painting count when a new painting is created
        
        static int getNumberOfPaintings(){
            return numberOfPaintings; // Return the current painting count
        };

        double value() const override{
                double age = created.calculateAgeInYears();
                double area = Width * Height;
                double value = age*area ;
                return value;
            
        }; // Override the value function to calculate the value of the painting
        std:: string toString() const override 
        {
            std::ostringstream oss;
            oss << "Artist: " << artist << "\n"
                << "Created: " << created.toString() << "\n"
                << "Acquired: " << acquired.toString() << "\n"
                << "Donated By: " << donatedBy << "\n"
                << "Description: " << description << "\n"
                << "Mediam: " ;
                switch (medium) {
                    case PaintingMedium::OIL:
                        oss << "Oil";
                        break;
                    case PaintingMedium::ACRYLIC:
                        oss << "Acrylic";
                        break;
                    case PaintingMedium::MIXEDMEDIA:
                        oss << "Mixed Media";
                        break;
                    case PaintingMedium::WATERCOLOR:
                        oss << "Watercolor";
                        break;
                }
                oss<<"\n Dimensions: "<<Width<<"ft x"<<Height<<" ft \n";
                oss<<"Value: $" << std::fixed << std::setprecision(2) << value() << "\n";
            return oss.str(); // Return the formatted string representation of the painting
        }; 

        virtual ~Painting() {
            // Destructor implementation (if needed)
        }
        bool operator==(const Painting& other) const {
            return this->value() == other.value();
        }
        
        bool operator!=(const Painting& other) const {
            return this->value() != other.value();
        }
        
        bool operator<(const Painting& other) const {
            return this->value() < other.value();
        }
        
        bool operator>(const Painting& other) const {
            return this->value() > other.value();
        }
        
        bool operator<=(const Painting& other) const {
            return this->value() <= other.value();
        }
        
        bool operator>=(const Painting& other) const {
            return this->value() >= other.value();
        }
        
    
        
        // bool operator<(const Painting& other) const {
        //     return this->value() < other.value();
        // }
        
        // bool operator>(const Painting& other) const {
        //     return this->value() > other.value();
        // }
        
};

#endif // "PAINTING_H"