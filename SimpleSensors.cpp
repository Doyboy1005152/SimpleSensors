#include "SimpleSensors.h"
#include <DHT.h>
#include <Keypad.h>
#include <SPI.h>
char keys[4][4] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
DHTSensor::DHTSensor(int pin, int dhtType) : _dht(pin, dhtType) {
    _pin = pin;
    _dht.begin();
}
float DHTSensor::readMeasurement(char measurement) {
    float result = NAN;
    if (measurement == 'C') {
        result = _dht.readTemperature();
    } else if (measurement == 'F') {
        result = _dht.readTemperature(true);
    } else if (measurement == 'K') {
        float tempC = _dht.readTemperature();
        if (!isnan(tempC)) {
            result = tempC + 273.15;
        }
    } else if (measurement == 'H') {
        result = _dht.readHumidity();
    }
    return result;
}
BoolSensor::BoolSensor(int pin, int mode) {
    _pin = pin;
    _mode = mode;
    if (_mode == PULLUP) {
        pinMode(_pin, INPUT_PULLUP);
    } else {
        pinMode(_pin, INPUT);
    }
}
bool BoolSensor::readBool() {
    int value = digitalRead(_pin);
    if (_mode == PULLUP) {
        return value == LOW;
    }
    return value == HIGH;
}
KeypadSensor::KeypadSensor(byte *rowPins, byte *colPins)
    : _keypad(Keypad(makeKeymap(keys), rowPins, colPins, 4, 4)) {}

char KeypadSensor::getKey() {
    char key = _keypad.getKey();
    if (key) {
        _keySequence += key;
    }
    return key;
}

String KeypadSensor::getKeySequenceAsString() {
    return _keySequence;  // Return the key sequence as a string
}

int KeypadSensor::getKeySequenceAsInt() {
    return _keySequence.toInt();  // Convert to integer if needed
}

void KeypadSensor::clearKeySequence() {
    _keySequence = "";
}
UltrasonicSensor::UltrasonicSensor(int trigPin, int echoPin) {
    _trigPin = trigPin;
    _echoPin = echoPin;
    pinMode(_trigPin, OUTPUT);
    pinMode(_echoPin, INPUT);
}
float UltrasonicSensor::getDistance(char unit) {
    digitalWrite(_trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_trigPin, LOW);
    long duration = pulseIn(_echoPin, HIGH);
    float distanceCm = duration * 0.034 / 2;
    if (unit == 'I' || unit == 'i') {
        return distanceCm * 0.3937;
    }
    return distanceCm;
}
