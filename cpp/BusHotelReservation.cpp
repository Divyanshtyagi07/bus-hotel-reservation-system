#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int BUS_ROWS = 4;
const int BUS_COLS = 5;
const int HOTEL_FLOORS = 3;
const int HOTEL_ROOMS = 4;

void printBusLayout(bool busSeats[BUS_ROWS][BUS_COLS]) {
    cout << "\nBus Seats Layout:\n";
    cout << "Rows 1 to " << BUS_ROWS << ", Columns 1 to " << BUS_COLS << "\n";
    for (int i = 0; i < BUS_ROWS; i++) {
        for (int j = 0; j < BUS_COLS; j++) {
            if (busSeats[i][j]) {
                cout << "[B] ";
            } else {
                cout << "[A] ";
            }
        }
        cout << "\n";
    }
}

void printHotelLayout(bool hotelRooms[HOTEL_FLOORS][HOTEL_ROOMS]) {
    cout << "\nHotel Rooms Layout:\n";
    for (int i = 0; i < HOTEL_FLOORS; i++) {
        cout << "Floor " << i + 1 << ": ";
        for (int j = 0; j < HOTEL_ROOMS; j++) {
            if (hotelRooms[i][j]) {
                cout << "[Booked] ";
            } else {
                cout << "[Free] ";
            }
        }
        cout << "\n";
    }
}

bool bookBusSeat(bool busSeats[BUS_ROWS][BUS_COLS], int row, int col) {
    if (row < 0 || row >= BUS_ROWS || col < 0 || col >= BUS_COLS) {
        cout << "Invalid bus seat location!\n";
        return false;
    }

    if (busSeats[row][col]) {
        cout << "Seat already booked.\n";
        return false;
    }

    busSeats[row][col] = true;
    cout << "Bus seat booked successfully.\n";
    return true;
}

bool bookHotelRoom(bool hotelRooms[HOTEL_FLOORS][HOTEL_ROOMS], int floor, int room) {
    if (floor < 0 || floor >= HOTEL_FLOORS || room < 0 || room >= HOTEL_ROOMS) {
        cout << "Invalid hotel room location!\n";
        return false;
    }

    if (hotelRooms[floor][room]) {
        cout << "Room already booked.\n";
        return false;
    }

    hotelRooms[floor][room] = true;
    cout << "Hotel room booked successfully.\n";
    return true;
}

void cancelBusSeat(bool busSeats[BUS_ROWS][BUS_COLS], int row, int col) {
    if (row < 0 || row >= BUS_ROWS || col < 0 || col >= BUS_COLS) {
        cout << "Invalid bus seat!\n";
        return;
    }

    if (!busSeats[row][col]) {
        cout << "This bus seat is not booked.\n";
    } else {
        busSeats[row][col] = false;
        cout << "Bus seat cancelled successfully.\n";
    }
}

void cancelHotelRoom(bool hotelRooms[HOTEL_FLOORS][HOTEL_ROOMS], int floor, int room) {
    if (floor < 0 || floor >= HOTEL_FLOORS || room < 0 || room >= HOTEL_ROOMS) {
        cout << "Invalid hotel room!\n";
        return;
    }

    if (!hotelRooms[floor][room]) {
        cout << "This hotel room is not booked.\n";
    } else {
        hotelRooms[floor][room] = false;
        cout << "Hotel room cancelled successfully.\n";
    }
}

int main() {
    bool busSeats[BUS_ROWS][BUS_COLS] = {false};
    bool hotelRooms[HOTEL_FLOORS][HOTEL_ROOMS] = {false};
    int choice;

    cout << "====================================\n";
    cout << "Bus/Hotel Reservation System\n";
    cout << "====================================\n";

    while (true) {
        cout << "\n1. Book Bus Seat\n";
        cout << "2. Book Hotel Room\n";
        cout << "3. Show Bus Availability\n";
        cout << "4. Show Hotel Availability\n";
        cout << "5. Cancel Bus Seat\n";
        cout << "6. Cancel Hotel Room\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int row, col;
            cout << "Enter bus row (1-" << BUS_ROWS << "): ";
            cin >> row;
            cout << "Enter bus column (1-" << BUS_COLS << "): ";
            cin >> col;
            bookBusSeat(busSeats, row - 1, col - 1);
        }
        else if (choice == 2) {
            int floor, room;
            cout << "Enter hotel floor (1-" << HOTEL_FLOORS << "): ";
            cin >> floor;
            cout << "Enter room number (1-" << HOTEL_ROOMS << "): ";
            cin >> room;
            bookHotelRoom(hotelRooms, floor - 1, room - 1);
        }
        else if (choice == 3) {
            printBusLayout(busSeats);
        }
        else if (choice == 4) {
            printHotelLayout(hotelRooms);
        }
        else if (choice == 5) {
            int row, col;
            cout << "Enter bus row (1-" << BUS_ROWS << "): ";
            cin >> row;
            cout << "Enter bus column (1-" << BUS_COLS << "): ";
            cin >> col;
            cancelBusSeat(busSeats, row - 1, col - 1);
        }
        else if (choice == 6) {
            int floor, room;
            cout << "Enter hotel floor (1-" << HOTEL_FLOORS << "): ";
            cin >> floor;
            cout << "Enter room number (1-" << HOTEL_ROOMS << "): ";
            cin >> room;
            cancelHotelRoom(hotelRooms, floor - 1, room - 1);
        }
        else if (choice == 7) {
            cout << "Thank you for using the reservation system.\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
