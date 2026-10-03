# Bus/Hotel Reservation System

This project is a beginner-friendly reservation system that handles:
- Bus seat booking
- Hotel room booking
- Availability checks using 2D arrays
- Conditional logic for booking and cancellation

It is implemented in both C++ and Python.

## Features
- Book a bus seat
- Book a hotel room
- View available seats and rooms
- Cancel bookings
- Search for availability in a simple menu-driven system

## Project Structure
- `cpp/BusHotelReservation.cpp` - C++ version
- `python/bus_hotel_reservation.py` - Python version

## How to run

### C++
```bash
cd cpp
g++ BusHotelReservation.cpp -o bus_hotel
./bus_hotel
```

### Python
```bash
cd python
python bus_hotel_reservation.py
```

## Example logic used
- Bus seats are stored in a 2D array like `busSeats[row][col]`
- Hotel rooms are stored in a 2D array like `hotelRooms[floor][room]`
- Each booking checks whether the selected seat/room is already occupied
- If available, it is marked as booked and the user is prompted for traveler details

## Notes
This is a simple console-based system designed for learning:
- 2D arrays
- loops and conditions
- functions
- menu-driven programs
