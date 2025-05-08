
#  Museum Artwork Inventory System
**Course:** CSC237 - Object-Oriented Programming  
**Semester:** Spring 2025  
**Student:** Vansh  
**Project Type:** Final Project

---

##  Project Description

This C++ project models a virtual museum that stores and manages multiple types of artwork using object-oriented programming principles. It supports:

- Paintings
- Sculptures
- Dance performances
- Films
- Music
- WrittenWord

Each type of artwork is represented by its own subclass that inherits from an abstract base class `ArtWork`.

---

##  Features Implemented

-  **Abstract Base Class**: `ArtWork` with pure virtual `toString()` and `value()`
-  **Subclasses**: `Painting`, `Sculpture`, `Dance`, `Film`, `Music`,`WrittenWord`
-  **Helper Classes**: `Date`, `Time`
-  **Operator Overloading**:
  - Stream output: `operator<<`
  - Comparison: `==`, `!=`, `<`, `>`, `<=`, `>=`
-  **Templates**: 
  - `findMin<T>()` and `findMax<T>()` to find the least/most valuable artworks
- **Polymorphism**:
  - Array of `ArtWork*` used to store and display various artwork types
-  **Exception Handling**:
  - Checks for invalid inputs (e.g., empty artist, negative dimensions)
-  **File Output**:
  - Saves artwork inventory to `MuseumInventory.txt`
-  UML Diagrams (submitted separately or added to this README)

---

##  File Overview

| File | Description |
|------|-------------|
| `main.cpp` | Driver program |
| `ArtWork.h` | Abstract base class |
| `Painting.h`  | Painting subclass |
| `Sculpture.h`  | Sculpture subclass |
| `Dance.h`  | Dance subclass |
| `Film.h`  | Film subclass |
| `Music.h`  | Music subclass |
|`WrittenWord.h` | WrittenWord subclass |
| `Time.h` | Helper class for durations |
| `Date.h` | Helper class for dates |
| `MuseumInventory.txt` | Output file (generated at runtime) |
| `README.md` | Project explanation and checklist |

---

## 🔧 How to Compile & Run

Using PowerShell or any terminal:

```bash
g++ main.cpp  -o project
.\project
```

---

##  How to Test

- Create artwork with valid and invalid input (e.g., empty artist)
- Verify exception handling is triggered
- Use `findMin()` and `findMax()` templates to locate extreme values
- Test output via `cout << *artworkPtr`
- Confirm file output to `MuseumInventory.txt`

---

##  UML Diagrams

UML diagrams for all classes will be attached or submitted as a separate file.

---

##  Notes

- All destructors are virtual for safety with polymorphism
- Extensive use of `const`, references, and `std::ostringstream` for clean output
- Memory is deallocated using `delete` for `ArtWork*` array items
- Project extensively commented and follows naming conventions

---

##  Author

**Vansh**  
Student, Computer Science  
BHCC – Spring 2025  
