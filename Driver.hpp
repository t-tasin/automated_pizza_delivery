#ifndef CLASSORDER_MAIN_FINALPROJECT_DRIVER_HPP
#define CLASSORDER_MAIN_FINALPROJECT_DRIVER_HPP

#include "Time.hpp"
#include "Order.hpp"
#include <string>
#include <deque>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;

class Driver {
public:
    Driver();
    ~Driver();

    void depart(Time time, Order* order);
    void deliver(Time time, float tip);
    void arrive(Time time);
    void logout();
    void login();

    int getTotalDeliveries();
    int getTotalMinDelivering();
    int getTotalMinDriving();
    float getTotalTips();
    string getStatus();
    void getSummary(int *totalDeliveries, int *tOrderTime);

private:
    int deliveryCount = 0;
    float tips = 0.00;
    bool loggedIn = false;
    bool delivering = false;

    Time orderTime;
    Time departTime;
    Time deliverTime;
    Time arriveTime;
    Order* myOrder = 0;


    int totalDrivingTime = 0; //from depart to arrive
    int totalOrderTime = 0; //from order to deliver
    int totalDeliveryTime = 0; //from depart to deliver
};

Driver::Driver() {}
Driver::~Driver() {}

void Driver::login() {
    if (loggedIn) {
        cout << "Error: Driver already logged in." << endl;
    }
    else {
        loggedIn = true;
        cout << "Logged in." << endl;
    }
}

void Driver::logout() {
    if (!loggedIn)
    {
        cout << "Error: Driver already logged out." << endl;
    }
    else if (delivering) {
        cout << "Error: Driver cannot logout while delivering." << endl;
    }
    else
    {
        loggedIn = false;
        cout << "Logged out." << endl;
    }
}

void Driver::depart(Time time, Order* order) {
    if (!loggedIn) {
        cout << "Error: Driver is logged out." << endl;
    }
    else if (delivering) {
        cout << "Error: Driver already delivering an order." << endl;
    }
    else if (order == nullptr){
        cout << "Error: Nothing to depart" << endl;
    }
    else {
            myOrder = order;
            orderTime = myOrder->getTime();
            delivering = true;
            departTime = time;
            cout << "Confirmed departure with " << myOrder->getInfo() << endl;
        }
}


void Driver::deliver(Time time, float tip) {
    if (!loggedIn || !delivering || myOrder == 0) {
        cout << "Error: Driver is logged out or is currently not delivering." << endl;
    }
    else if (myOrder == 0) {
        cout << "Error: Driver does not have an order to deliver." << endl;
    }
    else {
        deliveryCount++;
        deliverTime = time;
        tips = tips + tip;
        totalOrderTime = totalOrderTime + time.elapsedMin(deliverTime, orderTime);
        totalDeliveryTime = totalDeliveryTime + time.elapsedMin(deliverTime, departTime);
        totalDrivingTime = totalDrivingTime + time.elapsedMin(deliverTime, departTime);

        cout << "Confirmed delivery of " << myOrder->getInfo() << endl;
        delete myOrder;
        myOrder = 0;
    }
}

void Driver::arrive(Time time) {
    if (!loggedIn) {
        cout << "Error: Driver is logged out." << endl;
    }
    else if(!delivering) {
        cout << "Error: Driver is not currently delivering." << endl;
    }
    else {
        delivering = false;
        arriveTime = time;
        cout << "Confirmed driver arrival." << endl;
        totalDrivingTime = totalDrivingTime + time.elapsedMin(arriveTime, deliverTime);
    }
}

//Ian's Functions

/*
 * Pre: None
 * Post: Returns the total number of completed deliveries.
 */
int Driver::getTotalDeliveries() {
    return deliveryCount;
}

/*
 * Preconditions: None
 * Postcondition: Returns the total minutes spent delivering (i.e., between
 *                “order" and deliver” commands).
 */
int Driver::getTotalMinDelivering() {
    return totalOrderTime;
}

/*
 * Preconditions: None
 * Postcondition: Returns the total minutes spent driving (i.e., between
 *                “depart” and “arrive” commands).
 */
int Driver::getTotalMinDriving() {
    return totalDrivingTime;
}

/*
 * Pre: None
 * Post: Returns the total tips received, in dollars
 */
float Driver:: getTotalTips() {
    return tips;
}

/*
 * Preconditions: None
 * Postcondition: Returns a string containing the driver’s name, state
 *                (e.g., not logged in), and, if the driver is delivering an
 *                order, the departure time and toString of the order being delivered.
 */
string Driver::getStatus() {
    string status = "Logged out.";

    if (loggedIn) {
        status = "Logged in.";

        if (delivering && myOrder != 0) {
            status = status + " Currently delivering " + myOrder->getInfo();
        }
        else if (delivering) {
            status = status + " Returning from delivering an order.";
        }
    }

    return status;
}

void Driver::getSummary(int *totalDeliveries, int *tOrderTime) {
    cout << "     Total Deliveries Made: " << deliveryCount << endl;

    if (deliveryCount != 0) {
        cout << "     Total Tips Made: " << setprecision(2) << tips << endl;
        cout << "     Average Time Delivering: " << totalDeliveryTime/deliveryCount << endl;
        cout << "     Average Time Driving: " << totalDrivingTime/deliveryCount << endl;

        *totalDeliveries = *totalDeliveries + deliveryCount;
        *tOrderTime = *tOrderTime + totalOrderTime;
    }
}

#endif //CLASSORDER_MAIN_FINALPROJECT_DRIVER_HPP

//i Tasin i Sumaiya i Noah + 04:30 pizza1 + 04:40 pizza2 + 04:50 pizza3 = 04:35 pizza1 = 04:45 pizza2 = 04:55 pizza3 > 04:50 Tasin > 04:55 Sumaiya - 05:00 Tasin 2.5 - 05:05 Sumaiya 2.5 < 05:10 Tasin < 05:10 Sumaiya > 05:20 Tasin - 05:30 Tasin 3.3 < 05:35 Tasin