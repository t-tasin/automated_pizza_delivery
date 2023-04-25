# DOMINATO’S COMPUTERIZED DELIVERY SYSTEM

## Introduction

Dominato's Computerized Delivery System is a software solution to manage and streamline the pizza delivery process. This system allows the restaurant to handle orders, serve customers, manage delivery drivers, and track the status of orders and deliveries. The system is designed to make the order management process more efficient and user-friendly.

## Files

### Time.hpp

This header file contains the Time class, which represents a specific time of day. It is used to store and compare the time when orders are placed, when drivers depart, and when they arrive. The Time class has methods to compute the elapsed time between two Time objects and convert the time to a string representation.

### Order.hpp

This header file contains the Order class, which represents an individual order placed by a customer. Each order has a Time object representing when the order was placed, as well as a string containing information about the order. The Order class has methods to get and set the order's information and to get the time when the order was placed.

### Driver.hpp

This header file contains the Driver class, which represents a driver responsible for delivering orders. The Driver class has methods to log in and out, depart with an order, deliver an order, and arrive back at the restaurant. The class also keeps track of various delivery statistics, such as the total number of deliveries made, the total time spent driving, and the total tips received.

### Restaurant.hpp

This header file contains the Restaurant class, which represents the restaurant and manages the entire delivery process. The Restaurant class has methods to add and serve orders, manage delivery drivers, and display the status of orders waiting to be served or delivered. The class also provides a summary of the total number of deliveries, average delivery times, and driver-specific statistics.

## Usage

The Dominato's Computerized Delivery System is designed to be integrated into a restaurant management system. Users can interact with the system to add orders, serve orders, manage drivers, and track the status of orders and deliveries.

1. **Adding Orders**: The `addOrder` method in the Restaurant class can be used to add new orders to the queue of orders waiting to be served or cooked.

2. **Serving Orders**: The `serve` method in the Restaurant class can be used to move an order from the queue of orders waiting to be served to the queue of orders waiting to be delivered.

3. **Managing Drivers**: The Driver class provides methods to log drivers in and out, and manage the delivery process. Drivers can be logged in using the `login` method and logged out using the `logout` method. The `depart`, `deliver`, and `arrive` methods can be used to manage the driver's delivery process.

4. **Tracking Status**: The `status` method in the Restaurant class can be used to display the status of orders waiting to be served or delivered, as well as the status of logged-in drivers.

5. **Delivery Summary**: The `getSummary` method in the Driver class can be used to display a summary of delivery statistics, such as the total number of deliveries made, average delivery times, and driver-specific statistics.

## Conclusion

Dominato's Computerized Delivery System provides a comprehensive solution to manage and track the pizza delivery process. The system is designed to be easy to integrate and use, making it an ideal choice for improving the efficiency and user experience of the restaurant's delivery service.
