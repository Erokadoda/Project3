/*
* Class: CMSC140 CRN 40569
* Instructor: Professor Kechiantz 
* Project 3 Intermediate Deliverable 
* Description: This is a program which calculates the occupancy rate and total hotel income of various locations of the BlueMont Hotel chain. This information is calculated 
 for one night stayed at the hotel, displaying this and other pieces of information (e.g. total number of occupied rooms) to the user.
* Due Date: 07/05/24
* I pledge that I have completed the programming assignment
independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 Print your Name here: Ishan Pahwa 
*/
#include <iostream>
#include <iomanip>

const int SINGLE_ROOM_RATE = 60;
const int DOUBLE_ROOM_RATE = 75;
const int KING_ROOM_RATE = 100;
const int SUITE_ROOM_RATE = 150;
const int MAX_FLOORS = 5;
const int MAX_ROOMS_PER_FLOOR = 30;

int main() {
    int totalFloors, totalRooms, occupiedRooms;
    int totalOccupiedRooms = 0, totalHotelIncome = 0, totalUnoccupiedRooms = 0;
    double occupancyRate;
    int minRooms = MAX_ROOMS_PER_FLOOR + 1, minFloor = 0;

    std::cout << "Enter the number of floors in the hotel (not more than 5): ";
    std::cin >> totalFloors;

    for (int i = 1; i <= totalFloors; ++i) {
        std::cout << "Enter the total number of rooms for floor " << i << " (not more than 30): ";
        std::cin >> totalRooms;

        while (totalRooms < 1 || totalRooms > MAX_ROOMS_PER_FLOOR) {
            std::cout << "Invalid input. Enter the total number of rooms for floor " << i << " again: ";
            std::cin >> totalRooms;
        }

        std::cout << "Enter the number of occupied rooms for each room type on floor " << i << ":\n";
        int singleRooms, doubleRooms, kingRooms, suiteRooms;
        std::cin >> singleRooms >> doubleRooms >> kingRooms >> suiteRooms;

        while (singleRooms + doubleRooms + kingRooms + suiteRooms > totalRooms) {
            std::cout << "Total occupied rooms exceed total rooms. Enter again for floor " << i << ":\n";
            std::cin >> singleRooms >> doubleRooms >> kingRooms >> suiteRooms;
        }

        totalOccupiedRooms += singleRooms + doubleRooms + kingRooms + suiteRooms;
        totalUnoccupiedRooms += totalRooms - (singleRooms + doubleRooms + kingRooms + suiteRooms);
        totalHotelIncome += singleRooms * SINGLE_ROOM_RATE + doubleRooms * DOUBLE_ROOM_RATE +
            kingRooms * KING_ROOM_RATE + suiteRooms * SUITE_ROOM_RATE;

        if (totalRooms < minRooms) {
            minRooms = totalRooms;
            minFloor = i;
        }
    }

    occupancyRate = (static_cast<double>(totalOccupiedRooms) / (totalFloors * MAX_ROOMS_PER_FLOOR)) * 100;

    std::cout << "\nHotel Income: $" << std::fixed << std::setprecision(2) << totalHotelIncome << std::endl;
    std::cout << "Total Occupied Rooms: " << totalOccupiedRooms << std::endl;
    std::cout << "Total Unoccupied Rooms: " << totalUnoccupiedRooms << std::endl;
    std::cout << "Occupancy Rate: " << std::fixed << std::setprecision(2) << occupancyRate << "%" << std::endl;
    std::cout << "Floor with Minimum Rooms: " << minFloor << std::endl;

    if (occupancyRate < 60) {
        std::cout << "Occupancy rate is less than 60%. Consider strategies to improve it." << std::endl;
    }

    return 0;
}
