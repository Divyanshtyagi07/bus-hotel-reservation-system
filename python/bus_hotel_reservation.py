def print_bus_layout(bus_seats):
    print("\nBus Seats Layout:")
    for i in range(len(bus_seats)):
        row = []
        for j in range(len(bus_seats[i])):
            row.append("[Booked]" if bus_seats[i][j] else "[Available]")
        print(f"Row {i + 1}: {' '.join(row)}")


def print_hotel_layout(hotel_rooms):
    print("\nHotel Rooms Layout:")
    for i in range(len(hotel_rooms)):
        floor = []
        for j in range(len(hotel_rooms[i])):
            floor.append("[Booked]" if hotel_rooms[i][j] else "[Free]")
        print(f"Floor {i + 1}: {' '.join(floor)}")


def book_bus_seat(bus_seats, row, col):
    if row < 0 or row >= len(bus_seats) or col < 0 or col >= len(bus_seats[0]):
        print("Invalid bus seat location!")
        return False

    if bus_seats[row][col]:
        print("Seat already booked.")
        return False

    bus_seats[row][col] = True
    print("Bus seat booked successfully.")
    return True


def book_hotel_room(hotel_rooms, floor, room):
    if floor < 0 or floor >= len(hotel_rooms) or room < 0 or room >= len(hotel_rooms[0]):
        print("Invalid hotel room location!")
        return False

    if hotel_rooms[floor][room]:
        print("Room already booked.")
        return False

    hotel_rooms[floor][room] = True
    print("Hotel room booked successfully.")
    return True


def cancel_bus_seat(bus_seats, row, col):
    if row < 0 or row >= len(bus_seats) or col < 0 or col >= len(bus_seats[0]):
        print("Invalid bus seat!")
        return

    if not bus_seats[row][col]:
        print("This bus seat is not booked.")
    else:
        bus_seats[row][col] = False
        print("Bus seat cancelled successfully.")


def cancel_hotel_room(hotel_rooms, floor, room):
    if floor < 0 or floor >= len(hotel_rooms) or room < 0 or room >= len(hotel_rooms[0]):
        print("Invalid hotel room!")
        return

    if not hotel_rooms[floor][room]:
        print("This hotel room is not booked.")
    else:
        hotel_rooms[floor][room] = False
        print("Hotel room cancelled successfully.")


def main():
    bus_rows = 4
    bus_cols = 5
    hotel_floors = 3
    hotel_rooms = 4

    bus_seats = [[False for _ in range(bus_cols)] for _ in range(bus_rows)]
    hotel_rooms_grid = [[False for _ in range(hotel_rooms)] for _ in range(hotel_floors)]

    print("====================================")
    print("Bus/Hotel Reservation System")
    print("====================================")

    while True:
        print("\n1. Book Bus Seat")
        print("2. Book Hotel Room")
        print("3. Show Bus Availability")
        print("4. Show Hotel Availability")
        print("5. Cancel Bus Seat")
        print("6. Cancel Hotel Room")
        print("7. Exit")

        try:
            choice = int(input("Enter choice: "))
        except ValueError:
            print("Invalid choice. Please enter a number.")
            continue

        if choice == 1:
            try:
                row = int(input("Enter bus row (1-4): ")) - 1
                col = int(input("Enter bus column (1-5): ")) - 1
                book_bus_seat(bus_seats, row, col)
            except ValueError:
                print("Please enter valid numbers.")

        elif choice == 2:
            try:
                floor = int(input("Enter hotel floor (1-3): ")) - 1
                room = int(input("Enter room number (1-4): ")) - 1
                book_hotel_room(hotel_rooms_grid, floor, room)
            except ValueError:
                print("Please enter valid numbers.")

        elif choice == 3:
            print_bus_layout(bus_seats)

        elif choice == 4:
            print_hotel_layout(hotel_rooms_grid)

        elif choice == 5:
            try:
                row = int(input("Enter bus row (1-4): ")) - 1
                col = int(input("Enter bus column (1-5): ")) - 1
                cancel_bus_seat(bus_seats, row, col)
            except ValueError:
                print("Please enter valid numbers.")

        elif choice == 6:
            try:
                floor = int(input("Enter hotel floor (1-3): ")) - 1
                room = int(input("Enter room number (1-4): ")) - 1
                cancel_hotel_room(hotel_rooms_grid, floor, room)
            except ValueError:
                print("Please enter valid numbers.")

        elif choice == 7:
            print("Thank you for using the reservation system.")
            break

        else:
            print("Invalid choice. Please try again.")


if __name__ == "__main__":
    main()
