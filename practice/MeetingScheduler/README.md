# Meeting Scheduler System

A C++ implementation of a meeting room scheduling system that allows booking meetings across multiple rooms and sending notifications to attendees.

## Requirements

The system implements the following features:
1. Support for multiple meeting rooms (n rooms)
2. Book meetings in any available room for given time slots and capacity
3. Send notifications to all invited attendees
4. Track meetings for each room using a room calendar system

## Class Structure

- `User`: Manages user information (name, id, email)
- `Meeting`: Handles meeting details (time, attendees, capacity)
- `MeetingRoom`: Manages room availability and meetings
- `NotificationService`: Handles sending notifications to attendees
- `MeetingScheduler`: Core scheduler that coordinates room booking

## How to Build and Run

1. Make sure you have a C++ compiler installed (g++)
2. Open terminal in the project directory
3. Compile the code:
   ```bash
   g++ main.cpp -o scheduler
   ```
4. Run the program:
   ```bash
   ./scheduler
   ```