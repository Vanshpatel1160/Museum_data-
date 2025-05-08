#ifndef ARTWORK_H
#define ARTWORK_H

#include <string>
#include <iostream>
#include "Date.h" 



class ArtWork {
    protected:
        std:: string artist;
        Date created;   
        Date acquired;
        std:: string donatedBy;
        std:: string description;

        public:
        ArtWork(const std::string& artist, const Date& created, const Date& acquired,
                const std::string& donatedBy, const std::string& description)
            : artist(artist), created(created), acquired(acquired),
              donatedBy(donatedBy), description(description) {
                
              }
    
        virtual ~ArtWork() {}
    
        virtual std::string toString() const = 0;
        virtual double value() const = 0;


        friend std::ostream& operator<<(std::ostream& os, const ArtWork& art) {
            os << art.toString();
            return os;
            }
       
    };

#endif // ARTWORK_H

