/*
 * Name: Lab 5A-4
 * Class: COMSC-165
 * Date: 10/18/2018
 * Author: Tejas Shah
 * Description: It stores and prints weather informations using structures.
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct TempScale {
    double fahrenheit;
    double centigrade;
};

struct Reading {
    int windSpeed;
    double humidity;
    TempScale temperature;
};

int readInt() {
    int input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

double readDouble() {
    double input;
    cin >> input;
    while (cin.fail()) {
        cin.clear();
        cin.ignore();
        cin >> input;
    }

    cin.ignore();
    return input;
}

void showReading(const Reading &reading) {
    cout << "Wind Speed: " << reading.windSpeed << " mph" << endl;
    cout << "Humidity: " << setprecision(2) << fixed << reading.humidity << " %" << endl;
    cout << "Temperature: " << endl;
    cout << "  Fahrenheit: " << reading.temperature.fahrenheit << " F" << endl;
    cout << "  Centigrade: " << reading.temperature.centigrade << " C" << endl;
    cout << endl;
}

int promptWindspeed() {
    cout << "Enter wind speed: ";
    return readInt();
}

double promptHumidity() {
    cout << "Enter humidity: ";
    return readDouble();
}

double promptTempF() {
    cout << "Enter temperature in fahrenheit: ";
    return readDouble();
}

double promptTempC() {
    cout << "Enter temperature in centigrade: ";
    return readDouble();
}

void findReading(Reading &reading) {
    reading.windSpeed = promptWindspeed();
    reading.humidity = promptHumidity();
    reading.temperature.fahrenheit = promptTempF();
    reading.temperature.centigrade = promptTempC();
}

Reading getReading() {
    Reading reading = {
        promptWindspeed(),
        promptHumidity(),
        promptTempF(),
        promptTempC()
    };

    return reading;
}

void recordReading(Reading *reading) {
    reading->windSpeed = promptWindspeed();
    reading->humidity = promptHumidity();
    reading->temperature = {
        promptTempF(),
        promptTempC()
    };
}

int main() {
    Reading Temp1 = {37, 0.32d, {32, 0}};
    showReading(Temp1);

    Reading Temp2;
    findReading(Temp2);
    cout << endl;
    showReading(Temp2);

    Reading Temp3 = getReading();
    cout << endl;
    showReading(Temp3);

    Reading Temp4;
    recordReading(&Temp4);
    cout << endl;
    showReading(Temp4);

    return 0;
}
