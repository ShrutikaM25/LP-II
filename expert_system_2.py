class Flight:
    def __init__(self, destination, capacity):
        self.destination = destination
        self.capacity = capacity
        self.cargo_list = [] 

class Cargo:
    def __init__(self, cargo_type, weight, priority):
        self.type = cargo_type
        self.weight = weight
        self.priority = priority  

flight_schedule = {
    "Flight1": Flight("New York", 100),
    "Flight2": Flight("London", 150),
    "Flight3": Flight("Tokyo", 200)
}

def is_flight_available(destination, weight):
    for flight in flight_schedule.values():
        if flight.destination == destination and weight <= flight.capacity:
            return True
    return False

def assign_cargo_to_flights(cargo_list):
    print("Assigning cargo to flights:")
    
    # Sort cargo based on priority
    sorted_cargo = sorted(cargo_list, key=lambda cargo: cargo.priority, reverse=True)
    
    for cargo in sorted_cargo:
        assigned = False
        
        for flight_name, flight in flight_schedule.items():
            if (cargo.type == "Perishable" and flight.destination == "New York") or (cargo.type == "Fragile"):
                # Perishable cargo should be assigned to flights going to New York
                # Fragile cargo can be assigned to any flight
                if cargo.weight <= flight.capacity and is_flight_available(flight.destination, cargo.weight):
                    assigned = True
                    flight.cargo_list.append(cargo.type)  # Track cargo assigned to flight
                    print(f"Cargo type: {cargo.type}, Weight: {cargo.weight} kg, Assigned to flight: {flight_name} (Destination: {flight.destination})")
                    flight.capacity -= cargo.weight
                    break
        
        if not assigned:
            print(f"Unable to assign cargo type: {cargo.type}, Weight: {cargo.weight} kg to any available flight.")

if __name__ == "__main__":
    print("Welcome to the Cargo Scheduling Expert System!")
    print("Please enter details of the cargo (type, weight, priority separated by spaces), and type 'done' when finished:")
    
    cargo_list = []
    while True:
        user_input = input("> ")
        if user_input == "done":
            break
        
        cargo_details = user_input.split()
        cargo_type, weight, priority = cargo_details[0], int(cargo_details[1]), int(cargo_details[2])
        cargo_list.append(Cargo(cargo_type, weight, priority))
    
    assign_cargo_to_flights(cargo_list)
