Two separate concurrency problems. Part 1 is assigning tasks to limited resources as they become available. Part 2 is the barbershop problem.

Part 1:
Consider a sharable resource with the following characteristics:
1. As long as there are fewer than three processes using the resource, new processes can start using it right away.
2. Once there are three processes using the resource, all three must leave before any new processes can begin using it.

Part 2:
A barbershop consists of a waiting room with n chairs, and the barber room containing the barber chair. If there are no customers to be served, the barber goes to sleep. If a customer enters the barbershop and all chairs are occupied, then the customer leaves the shop. If the barber is busy, but chairs are available, then the customer sits in one of the free chairs. If the barber is asleep, the customer wakes up the barber. Write a program to coordinate the barber and the customers.
