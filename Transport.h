#pragma once
#include "Time.h"
// #include "User.h"

class Transport {
protected:
    size_t _cost, _capacity, _current;
    string _time;
	string _location;
	int _type;
	string _ID;
public:
    Transport(int cost = 0, int capacity = 0, int current = 0, string time = "", string location = "", int type = 0, string ID = "") {
        _cost = cost;
        _capacity = capacity;
        _current = current;
        _time = time;
        _location = location;
        _type = type;
        _ID = ID;
    }
    virtual ~Transport() {}
    virtual bool book(int x);
    virtual void showAvailable(Time t);
    virtual void cancel();
    virtual bool checkAvailable();
    friend class Facade;
};

class Grab : public Transport {
private:
public:
    Grab() : Transport() {}
    ~Grab() {}
    bool book(int x) {

    }
    void showAvailable(Time t) {

    }
    void cancel() {
        
    }
    bool checkAvailable() {

    }
};

class Taxi : public Transport {
private:
public:
    Taxi() : Transport() {}
    ~Taxi() {}
    bool book(int x) {

    }
    void showAvailable(Time t) {

    }
    void cancel() {

    }
    bool checkAvailable() {
        
    }
};

class Bus : public Transport {
private:
public:
    Bus() : Transport() {}
    ~Bus() {}
    bool book(int x) {

    }
    void showAvailable(Time t) {

    }
    void cancel() {

    }
    bool checkAvailable() {
        
    }
};