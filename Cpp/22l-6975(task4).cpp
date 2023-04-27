#include <iostream>
using namespace std;

class RationalNumber
{
private:
    int mNumerator;
    int mDenominator;

    void reduceFraction()
    {
        int gcd = calculateGreatestCommonDivisor(mNumerator, mDenominator);
        mNumerator /= gcd;
        mDenominator /= gcd;
    }

    int calculateGreatestCommonDivisor(int a, int b)
    {
        if (b == 0)
        {
            return a;
        }
        return calculateGreatestCommonDivisor(b, a % b);
    }

public:
    RationalNumber(int numerator = 1, int denominator = 1)
    {
        if (denominator == 0)
        {
            cout << "Error: denominator cannot be zero. Setting denominator to 1." << std::endl;
            mDenominator = 1;
            mNumerator = numerator;
        }
        else
        {
            mDenominator = abs(denominator);
            mNumerator = numerator;
        }
        reduceFraction();
    }

    friend RationalNumber add(const RationalNumber& r1, const RationalNumber& r2);
    friend RationalNumber subtract(const RationalNumber& r1, const RationalNumber& r2);

    void display()
    {
        cout << mNumerator << "/" << mDenominator << endl;
    }
};

RationalNumber add(const RationalNumber& r1, const RationalNumber& r2)
{
    int numerator = (r1.mNumerator * r2.mDenominator) + (r2.mNumerator * r1.mDenominator);
    int denominator = r1.mDenominator * r2.mDenominator;
    RationalNumber result(numerator, denominator);
    return result;
}

RationalNumber subtract(const RationalNumber& r1, const RationalNumber& r2)
{
    int numerator = (r1.mNumerator * r2.mDenominator) - (r2.mNumerator * r1.mDenominator);
    int denominator = r1.mDenominator * r2.mDenominator;
    RationalNumber result(numerator, denominator);
    return result;
}

int main()
{
    RationalNumber fraction1(3, 4);
    RationalNumber fraction2(1, 2);

    cout << "Fraction 1: ";
    fraction1.display();

    cout << "Fraction 2: ";
    fraction2.display();

    RationalNumber sum = add(fraction1, fraction2);
    cout << "Sum of Fraction 1 and Fraction 2: ";
    sum.display();

    RationalNumber difference = subtract(fraction1, fraction2);
    cout << "Difference of Fraction 1 and Fraction 2: ";
    difference.display();

    RationalNumber invalidFraction(3, 0);
    cout << "Invalid Fraction: ";
    invalidFraction.display();

    system("pause");

    return 0;
}
