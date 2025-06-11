#include <bits/stdc++.h>
using namespace std;

/*
We are going to implement a parking lot system.
Requirements
Create a command-line application for the parking lot system with the following requirements.

The functions that the parking lot system can do:
Create the parking lot.
Add floors to the parking lot.
Add a parking lot slot to any of the floors.
Given a vehicle, it finds the first available slot, books it, creates a ticket, parks the vehicle, and finally returns the ticket.
Unparks a vehicle given the ticket id.
Displays the number of free slots per floor for a specific vehicle type.
Details about the Vehicles:
Every vehicle will have a type, registration number, and color.
Different Types of Vehicles:
Car
Bike
Truck
Details about the Parking Slots:
Each type of slot can park a specific type of vehicle.
No other vehicle should be allowed by the system.
Finding the first available slot should be based on:
The slot should be of the same type as the vehicle.
The slot should be on the lowest possible floor in the parking lot.
The slot should have the lowest possible slot number on the floor.
Numbered serially from 1 to n for each floor where n is the number of parking slots on that floor.
Details about the Parking Lot Floors:
Numbered serially from 1 to n where n is the number of floors.
Might contain one or more parking lot slots of different types.
We will assume that the first slot on each floor will be for a truck, the next 2 for bikes, and all the other slots for cars.
Details about the Tickets:
The ticket id would be of the following format:
<parking_lot_id>_<floor_no>_<slot_no>
Example: PR1234_2_5 (denotes 5th slot of 2nd floor of parking lot PR1234)
We can assume that there will only be 1 parking lot. The ID of that parking lot is PR1234.
*/
enum class VechicleType{
    CAR,
    TRUCK,
    BIKE
};

class Slot{
    int slotNumber;
    VechicleType slotType;
    bool occupied;
public:
    Slot(int slotNumber, VechicleType slotType) : slotNumber(slotNumber), slotType(slotType), occupied(false) {}
    int getSlotNumber(){
        return slotNumber;
    }
    VechicleType getSlotType(){
        return slotType;
    }
    bool isOccupied(){
        return occupied;
    }
    void setOccupied(bool isOccupied){
        this->occupied = isOccupied;
    }
};

class Floor{
    int floorNumber;
    vector<Slot*> slots;
public:
    Floor(int floorNumber, int numSlots){
        this->floorNumber = floorNumber;

        if(numSlots>=1){
            slots.push_back(new Slot(1, VechicleType::TRUCK));
        }
        if(numSlots>=2){
            slots.push_back(new Slot(2, VechicleType::BIKE));
        }
        if(numSlots>=3){
            slots.push_back(new Slot(3, VechicleType::BIKE));
        }
        for(int i=4;i<=numSlots;i++){
            slots.push_back(new Slot(i, VechicleType::CAR));
        }
    }

    int getFreeSlot(VechicleType vechicleType){
        for(int i=0;i<slots.size();i++){
            if(slots[i]->getSlotType()==vechicleType && !slots[i]->isOccupied()){
                return i;
            }
        }
        return -1;
    }

    // return true if successfully parked
    string parkVehicle(VechicleType vechicleType){
        int slotNumber = getFreeSlot(vechicleType);
        if(slotNumber==-1){
            return "";
        }
        slots[slotNumber]->setOccupied(true);
        return to_string(floorNumber)+"_"+to_string(slotNumber+1);
    }
};

class ParkingLot{
    string parkingLotId;
    vector<Floor*> floors;
public:
    ParkingLot(string parkingLotId) : parkingLotId(parkingLotId) {}

    void addFloor(int floorNumber, int numSlots){
        floors.push_back(new Floor(floorNumber, numSlots));
    }

    string parkVehicle(VechicleType vechicleType){
        for(int i=0;i<floors.size();i++){
            string ticket = floors[i]->parkVehicle(vechicleType);
            if(ticket!=""){
                return parkingLotId+"_"+ticket;
            }
        }
        return "-1";
    }
};

int main(){
    ParkingLot parkingLot("PR1234");
    parkingLot.addFloor(1, 10);
    parkingLot.addFloor(2, 10);

    string ticket = parkingLot.parkVehicle(VechicleType::CAR);
    cout<<ticket<<endl;
    string ticket4 = parkingLot.parkVehicle(VechicleType::CAR);
    cout<<ticket4<<endl;

    string ticket2 = parkingLot.parkVehicle(VechicleType::BIKE);
    cout<<ticket2<<endl;

    string ticket3 = parkingLot.parkVehicle(VechicleType::TRUCK);
    cout<<ticket3<<endl;


    return 0;
}