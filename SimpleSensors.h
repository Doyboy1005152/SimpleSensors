#ifndef SIMPLESENSORS_H
#define SIMPLESENSORS_H
#include <Keypad.h>
#include <DHT.h>
#define PULLUP 1
#define BINARY 0
class DHTSensor {
public:
    DHTSensor(int pin, int dhtType);
    float readMeasurement(char measurement);
private:
    DHT _dht;
    int _pin;
};
class BoolSensor {
public:
    BoolSensor(int pin, int mode);
    bool readBool();
private:
    int _pin;
    int _mode;
};
class KeypadSensor {
private:
    Keypad _keypad;
    String _keySequence;

public:
    KeypadSensor(byte *rowPins, byte *colPins);

    char getKey();
    String getKeySequenceAsString();
    int getKeySequenceAsInt();
    void clearKeySequence();
};

class UltrasonicSensor {
public:
    UltrasonicSensor(int trigPin, int echoPin);
    float getDistance(char unit);
private:
    int _trigPin;
    int _echoPin;
};
#endif
