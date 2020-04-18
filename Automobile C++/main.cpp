#include "Automobile.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <conio.h>
#include <Windows.h>
#include <ctime>

using namespace std;

double KMH_CMS(double kmh);
double CMS_KMH(double cms);

double KMH_CMS(double kmh)
{
    double cms;
    cms = (kmh * 1000.00 * 100) / 3600.00;
    return cms;
}

double CMS_KMH(double cms)
{
    double kmh;
    kmh = (cms * 3600.00) / (1000 * 100.00);
    return kmh;
}

class Car : public Automobile
{
protected:
    double TurnAngle, FinalAngle;
    double MaxSpeed;
    double IncreaseofSpeed, distPerLiter;

public:
    Car() : Automobile("Car")
    {
        SetInitialPosition(0, 0);
        SetInitialDirection(0, 1);
        fuel = 30;
        TurnAngle = 5.00;
        FinalAngle = 0;
        MaxSpeed = KMH_CMS(120);
        distPerLiter = 8 * 1000 * 100.00; //It's cm/liter ;
        IncreaseofSpeed = KMH_CMS(10);
        speed = 0;
    }

    void UpdateDirection()
    {
        directionX = sin(FinalAngle * acos(-1) / 180.00);
        directionY = cos(FinalAngle * acos(-1) / 180.00);
    }

    void TurnRight()
    {
        FinalAngle += TurnAngle;
        UpdateDirection();
    }
    void TurnLeft()
    {
        FinalAngle -= TurnAngle;
        UpdateDirection();
    }
    void IncreaseSpeed()
    {
        if (speed + IncreaseofSpeed <= MaxSpeed)
        {
            speed += IncreaseofSpeed;
        }
        else
        {
            speed = MaxSpeed;
            cout << "Car speed crosses the Maximum speed!!! Speed is set to maximum speed." << endl;
        }
    }
    void DecreaseSpeed()
    {
        if (speed - IncreaseofSpeed >= 0)
        {
            speed -= IncreaseofSpeed;
        }
        else
        {
            speed = 0;
            cout << "Car speed crosses the minimum speed. Speed is set to zero." << endl;
        }
    }
    void Move()
    {
        double fuelSpentPerSecond;
        fuelSpentPerSecond = speed * 1.0 / distPerLiter;

        if (fuel > 0)
        {
            posX += directionX * speed * 1.00;
            posY += directionY * speed * 1.00;
            fuel -= fuelSpentPerSecond;
        }
        else
        {
            fuel = 0;
            speed = 0;
        }
    }
};

class SUV : public Automobile
{
protected:
    double TurnAngle, FinalAngle;
    double MaxSpeed;
    double IncreaseofSpeed, distPerLiter;

public:
    SUV() : Automobile("SUV")
    {
        SetInitialPosition(0, 0);
        SetInitialDirection(0, 1);
        fuel = 50;
        TurnAngle = 10;
        FinalAngle = 0;
        MaxSpeed = KMH_CMS(100);
        distPerLiter = 6 * 1000 * 100.00;
        IncreaseofSpeed = KMH_CMS(8);
        speed = 0;
    }

    void UpdateDirection()
    {
        directionX = sin(FinalAngle * acos(-1) / 180.00);
        directionY = cos(FinalAngle * acos(-1) / 180.00);
    }

    void TurnRight()
    {
        FinalAngle += TurnAngle;
        UpdateDirection();
    }
    void TurnLeft()
    {
        FinalAngle -= TurnAngle;
        UpdateDirection();
    }
    void IncreaseSpeed()
    {
        if (speed + IncreaseofSpeed <= MaxSpeed)
        {
            speed += IncreaseofSpeed;
        }
        else
        {
            speed = MaxSpeed;
            cout << "Car speed crosses the Maximum speed!!! Speed is set to maximum speed." << endl;
        }
    }
    void DecreaseSpeed()
    {
        if (speed - IncreaseofSpeed >= 0)
        {
            speed -= IncreaseofSpeed;
        }
        else
        {
            speed = 0;
            cout << "Car speed crosses the minimum speed. Speed is set to zero." << endl;
        }
    }
    void Move()
    {
        double fuelSpentPerSecond;
        fuelSpentPerSecond = speed * 1.0 / distPerLiter;

        if (fuel > 0)
        {
            posX += directionX * speed * 1.00;
            posY += directionY * speed * 1.00;
            fuel -= fuelSpentPerSecond;
        }
        else
        {
            fuel = 0;
            speed = 0;
        }
    }
};

class Gear
{
public:
    double MaxRange, MinRange;
};

class Bus : public AutomobileWithManualXmission
{
protected:
    double TurnAngle, FinalAngle;
    double MaxSpeed;
    double IncreaseofSpeed, distPerLiter;

    class Gear ManualGear[6];

public:
    Bus() : AutomobileWithManualXmission("Bus")
    {
        SetInitialPosition(0, 0);
        SetInitialDirection(0, 1);
        fuel = 80;
        TurnAngle = 15;
        FinalAngle = 0;
        MaxSpeed = KMH_CMS(80);
        distPerLiter = 4 * 1000 * 100.00;
        IncreaseofSpeed = KMH_CMS(6);
        speed = 0;
        ManualGear[0].MinRange = 0;
        ManualGear[0].MaxRange = 0;
        ManualGear[1].MinRange = 0;
        ManualGear[1].MaxRange = 20;
        ManualGear[2].MinRange = 10;
        ManualGear[2].MaxRange = 30;
        ManualGear[3].MinRange = 25;
        ManualGear[3].MaxRange = 45;
        ManualGear[4].MinRange = 35;
        ManualGear[4].MaxRange = 60;
        ManualGear[5].MinRange = 50;
        ManualGear[5].MaxRange = 99999999999999;
    }

    void UpdateDirection()
    {
        directionX = sin(FinalAngle * acos(-1) / 180.00);
        directionY = cos(FinalAngle * acos(-1) / 180.00);
    }

    void TurnRight()
    {
        FinalAngle += TurnAngle;
        UpdateDirection();
    }
    void TurnLeft()
    {
        FinalAngle -= TurnAngle;
        UpdateDirection();
    }
    void IncreaseSpeed()
    {

        if (speed + IncreaseofSpeed <= KMH_CMS(ManualGear[gearPosition].MaxRange))
        {
            speed += IncreaseofSpeed;
        }
        else if (speed + IncreaseofSpeed > KMH_CMS(ManualGear[gearPosition].MaxRange))
        {
            speed = KMH_CMS(ManualGear[gearPosition].MaxRange);
            cout << "Car speed crosses the Maximum speed!!! Speed is set to maximum speed." << endl;
        }
    }
    void DecreaseSpeed()
    {
        if (speed - IncreaseofSpeed >= KMH_CMS(ManualGear[gearPosition].MinRange))
        {
            speed -= IncreaseofSpeed;
        }
        else if (speed - IncreaseofSpeed < KMH_CMS(ManualGear[gearPosition].MinRange))
        {
            speed = KMH_CMS(ManualGear[gearPosition].MinRange);
            cout << "Car speed crosses the minimum speed. Speed is set to minimum speed." << endl;
        }
    }
    void Move()
    {
        double fuelSpentPerSecond;
        fuelSpentPerSecond = speed * 1.0 / distPerLiter;

        if (fuel > 0)
        {
            posX += directionX * speed * 1.00;
            posY += directionY * speed * 1.00;
            fuel -= fuelSpentPerSecond;
        }
        else
        {
            fuel = 0;
            speed = 0;
        }
    }
};

class Truck : public AutomobileWithManualXmission
{
protected:
    double TurnAngle, FinalAngle;
    double MaxSpeed;
    double IncreaseofSpeed, distPerLiter;

    class Gear ManualGear[6];

public:
    Truck() : AutomobileWithManualXmission("Truck")
    {
        SetInitialPosition(0, 0);
        SetInitialDirection(0, 1);
        fuel = 100;
        TurnAngle = 25;
        FinalAngle = 0;
        MaxSpeed = KMH_CMS(60);
        distPerLiter = 2 * 1000 * 100.00;
        IncreaseofSpeed = KMH_CMS(4);
        speed = 0;
        ManualGear[0].MinRange = 0;
        ManualGear[0].MaxRange = 0;
        ManualGear[1].MinRange = 0;
        ManualGear[1].MaxRange = 20;
        ManualGear[2].MinRange = 10;
        ManualGear[2].MaxRange = 30;
        ManualGear[3].MinRange = 25;
        ManualGear[3].MaxRange = 45;
        ManualGear[4].MinRange = 35;
        ManualGear[4].MaxRange = 60;
        ManualGear[5].MinRange = 50;
        ManualGear[5].MaxRange = 9999999999999;
    }

    void UpdateDirection()
    {
        directionX = sin(FinalAngle * acos(-1) / 180.00);
        directionY = cos(FinalAngle * acos(-1) / 180.00);
    }

    void TurnRight()
    {
        FinalAngle += TurnAngle;
        UpdateDirection();
    }
    void TurnLeft()
    {
        FinalAngle -= TurnAngle;
        UpdateDirection();
    }
    void IncreaseSpeed()
    {

        if (speed + IncreaseofSpeed <= KMH_CMS(ManualGear[gearPosition].MaxRange))
        {
            speed += IncreaseofSpeed;
        }
        else if (speed + IncreaseofSpeed > KMH_CMS(ManualGear[gearPosition].MaxRange))
        {
            speed = KMH_CMS(ManualGear[gearPosition].MaxRange);
            cout << "Car speed crosses the Maximum speed!!! Speed is set to maximum speed." << endl;
        }
    }
    void DecreaseSpeed()
    {
        if (speed - IncreaseofSpeed >= KMH_CMS(ManualGear[gearPosition].MinRange))
        {
            speed -= IncreaseofSpeed;
        }
        else if (speed - IncreaseofSpeed < KMH_CMS(ManualGear[gearPosition].MinRange))
        {
            speed = KMH_CMS(ManualGear[gearPosition].MinRange);
            cout << "Car speed crosses the minimum speed. Speed is set to minimum speed." << endl;
        }
    }
    void Move()
    {
        double fuelSpentPerSecond;
        fuelSpentPerSecond = speed * 1.0 / distPerLiter;

        if (fuel > 0)
        {
            posX += directionX * speed * 1.00;
            posY += directionY * speed * 1.00;
            fuel -= fuelSpentPerSecond;
        }
        else
        {
            fuel = 0;
            speed = 0;
        }
    }
};
