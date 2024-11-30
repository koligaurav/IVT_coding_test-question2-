# City Road Network Optimization

This quetion helps optimize the road network in a city by prioritizing road construction projects, searching for specific projects, and determining the minimum number of roads (and their total cost) required to connect all areas of the city using **Minimum Spanning Tree (MST)** concepts.

---

## **Features**
1. **Sort Projects**: Sorts road construction projects by priority (descending) and cost (descending for same priority).
2. **Search Projects**: Allows searching for a specific project by its identifier.
3. **Minimum Connection Plan (MST)**: Calculates the minimum set of roads needed to connect all areas of the city with the minimum total cost.

---

## **Dependencies**
- C++ Compiler: Requires a C++17 or later-compatible compiler (e.g., GCC, Clang, or MSVC).
- Standard Template Library (STL): Utilized for sorting, vector manipulation, and graph algorithms.

---

## **How to Run the Code**

### **Steps to Execute**
1. **Clone the Repository**:
   ```bash
   git clone <repository_url>
   cd <repository_name>

2. **Compile the Code: Use any C++ compiler. For example**:
    ``` bash
   g++ -std=c++17 -o city_road_network city_road_network.cpp>

2. **Run the Program:**:
    ``` bash
   ./city_road_network
4  **Input**:

   Enter the number of road projects.
   Provide details for each project:
   Identifier (e.g., road1)
   Priority (integer)
   Cost (integer)
   Two Areas it connects (e.g., A1 A2)
   End each project input by entering 0.
   Example input 
   
5
road1 4 100 A1 A2
road2 3 150 A2 A3
road3 5 200 A3 A4
road4 4 50 A4 A1
road5 5 120 A2 A4


5 **Search for a Project**:
   Enter a project identifier to search for its existence and position in the sorted list. Example:
   ```bash 
   Enter road identifier to search: road4





