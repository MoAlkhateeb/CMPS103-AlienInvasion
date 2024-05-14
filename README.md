# Aliens - Simulate or Surrender 


## Description 
This Project is part of a group Project in a Data Strucutres & Algorithms Course (CMPS103) at Cairo University Faculty of Engineering (CUFE).

The Project is a simulation of a game where using an input file seed you can create different war scenarios between two armies, the first army is the earth and the second army is the aliens. The game is a turn-based game where each army has a number of units and each unit has a number of health points and attack points. The game ends when one of the armies is completely destroyed and at least one unit is left in the other army.


## Data Structures Used
- **Queue**: Implemented using a Singly Linked List. Used to store the units in the order of their creation.
- **Stack**: Implemented using an Array. Used to store the units for last in first out access.
- **Deque**: Implemented using a Doubly Linked List. Used to store the units in the order of their creation and to access the first and last units in O(1) time.
- **Priority Queue**: Implemented using a Singly Linked List. Used to prioritize units with a higher health + attack combination.
