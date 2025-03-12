# SimpleSensors Library

## Overview
SimpleSensors is a lightweight Arduino library that provides easy-to-use classes for interacting with common sensors, including:
- DHT Temperature & Humidity Sensors
- Boolean (Digital) Sensors
- Keypads
- Ultrasonic Distance Sensors
- The library is updated around every month for new sensors. However, for a change, just open an issue

## Features
- Simple API for reading sensor data
- Support for multiple sensor types
- Keypad input handling with sequence storage

## Installation
### Using the Arduino IDE
1. Download the `SimpleSensors.h` file from this repository.
2. Create a new folder named `SimpleSensors` inside your Arduino `libraries` folder.
   - The default location for Arduino libraries is: `Documents/Arduino/libraries/`
3. Move the downloaded `SimpleSensors.h` file into the `SimpleSensors` folder.
4. Restart the Arduino IDE if it was open.
5. Include the library in your sketch:
   ```cpp
   #include "SimpleSensors.h"
   ```

### Using Git
1. Open a terminal and navigate to your Arduino libraries folder:
   ```sh
   cd ~/Documents/Arduino/libraries/
   ```
2. Clone the repository:
   ```sh
   git clone <repository_url> SimpleSensors
   ```
3. Restart the Arduino IDE and include the library in your code.

## Classes & Usage

### `DHTSensor`
Handles DHT temperature and humidity sensors.

#### Constructor:
```cpp
DHTSensor(int pin, int dhtType);
```
- `pin`: GPIO pin connected to the DHT sensor.
- `dhtType`: DHT model (e.g., `DHT11`, `DHT22`).

#### Method:
```cpp
float readMeasurement(char measurement);
```
- `measurement`: `'T'` for temperature, `'H'` for humidity.

### `BoolSensor`
Reads digital (boolean) sensors.

#### Constructor:
```cpp
BoolSensor(int pin, int mode);
```
- `pin`: GPIO pin connected to the sensor.
- `mode`: `PULLUP` or `BINARY`.

#### Method:
```cpp
bool readBool();
```
Returns `true` or `false` based on sensor state.

### `KeypadSensor`
Handles a matrix keypad input.

#### Constructor:
```cpp
KeypadSensor(byte *rowPins, byte *colPins);
```
- `rowPins`: Array of row pin numbers.
- `colPins`: Array of column pin numbers.

#### Methods:
```cpp
char getKey();
```
Returns the most recent key pressed.

```cpp
String getKeySequenceAsString();
```
Returns the recorded key sequence as a string.

```cpp
int getKeySequenceAsInt();
```
Returns the recorded key sequence as an integer.

```cpp
void clearKeySequence();
```
Clears the stored key sequence.

### `UltrasonicSensor`
Measures distance using an ultrasonic sensor.

#### Constructor:
```cpp
UltrasonicSensor(int trigPin, int echoPin);
```
- `trigPin`: Trigger pin of the ultrasonic sensor.
- `echoPin`: Echo pin of the ultrasonic sensor.

#### Method:
```cpp
float getDistance(char unit);
```
- `unit`: `'C'` for centimeters, `'I'` for inches.

## License
This project is licensed under the MIT License.

## Contributing
Pull requests are welcome! Feel free to improve and expand the library.

## Contact
For any issues or suggestions, please open an issue in the repository.

