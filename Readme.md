# How to compile and run the code:
```
	$ make all
	$ ./RoomBookingSystem
```
# How to clean:
```
	$ make clean
```
# Question:
This assignment involves developing a very simple room booking system. The rooms have the following attributes: name, area, number of doors, and address. The location is given in terms of two dimensional coordinates `(X,Y)` of the center of the room. An
example room description is following:

* Rooms:	
```
Name	Area	Number of doors	X	Y
Room1	90	2		100	250
```	
* Labs:	
```
Name	Area	Number of doors	X	Y	Number of computers
Room1	90	2		100	250	40
```	
* Lecture Halls	
```
Name	Area	Number of doors	X	Y	Number of chairs               
Room1	90	2		100	250	35
```
	
1. Write a program for an online room booking system. The program should have capability to add new room to the system.
2. Read the room details from the file “ROOM.txt” and add to the system using the add functionality. You can assume maximum number of rooms to be 1000.
3. Extend the system to add Labs which have the following attributes: name, area, number of doors, location (X,Y), and number of computers. Read the lab details from the file “LAB.txt” and add to the system.
4. Further extend the system to have lecture halls with the following attributes: name, area, number of doors, location (X,Y), number of chairs. 
Read the details from the file “ROOM.txt”, “LAB.txt” and “LEC.txt” and add to the system.

* Functionalities: The developed system should implement the following functionalities:
	1. The program should be able to add rooms, labs, or lecture halls to the system dynamically.
	2. The program should be able to remove a room, lab, or lecture hall from the system.
	3. The program should have a mechanism to book a room, lab, or lecture hall.
	4. A person needs 30 units of the area to sleep in a room. The program should give the minimum number of rooms required to accommodate given number of persons.
	5. The program should be able to find the smallest lecture hall that can accommodate the given number of students [use chair information].
	6. The program should find the lab with least equipment density (computers per area unit) and should be able to add new equipment to the system[increasing the number of equipments is sufficient].
	7. Find a room nearest to the given location.
	8. Mechanism to book or unbook a room, lab, and lecture hall.
	9. Program should be able to print all details of the given room, lab, and lecture hall.
	10. When you exit the program, the system must store current booking status in a text file. The text file is loaded back to memory when the program starts again. 

Overall, the students should use the following C++ features at least once in the code:
* Function overloading
* Operator overloading
* Constructors and destructors
* Inheritance
* Virtual functions
* Dynamic memory allocation
* Function templates
* Access specifiers

You are allowed to add new functionalities to the system to use these features. Please mention new additions during the assignment demo.
