#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class bigint
{
private:
    int v[5];

public:
    bigint()
    {
        for (int i = 0; i < 5; i++)
        {
            v[i] = 0;
        }
    }

    bigint(int x0)
    {
        for (int i = 1; i < 5; i++)
        {
            v[i] = 0;
        }
        v[0] = x0;
    }

    bigint(int x0, int x1)
    {
        for (int i = 2; i < 5; i++)
        {
            v[i] = 0;
        }
        v[0] = x0;
        v[1] = x1;
    }

    bigint(int x0, int x1, int x2)
    {
        for (int i = 3; i < 5; i++)
        {
            v[i] = 0;
        }
        v[0] = x0;
        v[1] = x1;
        v[2] = x2;
    }

    bigint(int x0, int x1, int x2, int x3)
    {
        v[0] = x0;
        v[1] = x1;
        v[2] = x2;
        v[3] = x3;
        v[4] = 0;
    }

    bigint(int x0, int x1, int x2, int x3, int x4)
    {
        v[0] = x0;
        v[1] = x1;
        v[2] = x2;
        v[3] = x3;
        v[4] = x4;
    }

    friend ostream &operator<<(std::ostream &os, const bigint &other)
    {
        int j = 4;
        while (j > 0 && other.v[j] == 0)
            j--;

        os << other.v[j];

        for (int i = j - 1; i >= 0; i--)
            os << setfill('0') << setw(9) << other.v[i];

        return os;
    }

    friend istream &operator>>(std::istream &is, bigint &other)
    {
        char str[46];
        is >> str;

        int len = strlen(str);
        int j = 0;

        for (int i = len - 1; i >= 0; i -= 9)
        {
            int start = (i >= 9) ? i - 8 : 0;
            int digits = (i >= 9) ? 9 : (i + 1);

            int val = 0;
            for (int k = start; k <= i; k++)
                val = val * 10 + (str[k] - '0');

            other.v[j++] = val;
        }

        return is;
    }

    bool operator<(const bigint &other) const
    {
        bool flag;
        for (int i = 4; i >= 0; i--)
        {
            if (v[i] < other.v[i])
                flag = true;
            else if (v[i] > other.v[i])
                flag = false;
        }
        return flag;
    }

    bigint operator+(const bigint &other) const
    {
        bigint result;
        int carry = 0;

        for (int i = 0; i < 5; i++)
        {
            int sum = v[i] + other.v[i] + carry;
            result.v[i] = sum % 1000000000;
            carry = sum / 1000000000;
        }

        return result;
    }

    bigint operator-(const bigint &other) const
    {
        bigint result;
        int borrow = 0;

        for (int i = 0; i < 5; i++)
        {
            int diff = v[i] - other.v[i] - borrow;

            if (diff < 0)
            {
                diff += 1000000000;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            result.v[i] = diff;
        }

        return result;
    }

    bool operator>(const bigint &other) const
    {
        bool flag;
        for (int i = 4; i >= 0; i--)
        {
            if (v[i] > other.v[i])
                flag = true;
            else if (v[i] < other.v[i])
                flag = false;
        }
        return flag;
    }

    bool operator<=(const bigint &other) const
    {
        return !(other < *this);
    }

    bool operator>=(const bigint &other) const
    {
        return !(*this < other);
    }

    bool operator==(const bigint &other) const
    {
        for (int i = 0; i < 5; i++)
        {
            if (v[i] != other.v[i])
                return false;
        }
        return true;
    }

    bool operator!=(const bigint &other) const
    {
        return !(*this == other);
    }
};

int main()
{
    bigint x;
    bigint y;

    if (x == y)
        cout << x << " is equal to " << y << "." << endl;
    if (x != y)
        cout << x << " is not equal to " << y << "." << endl;
    if (x > y)
        cout << x << " is larger than " << y << "." << endl;
    if (x >= y)
        cout << x << " is larger than or equal to " << y << "." << endl;
    if (x < y)
        cout << x << " is smaller than " << y << "." << endl;
    if (x <= y)
        cout << x << " is smaller than or equal to " << y << "." << endl;

    bigint x1(123456789);
    bigint y1(111111111);

    if (x1 == y1)
        cout << x1 << " is equal to " << y1 << "." << endl;
    if (x1 != y1)
        cout << x1 << " is not equal to " << y1 << "." << endl;
    if (x1 > y1)
        cout << x1 << " is larger than " << y1 << "." << endl;
    if (x1 >= y1)
        cout << x1 << " is larger than or equal to " << y1 << "." << endl;
    if (x1 < y1)
        cout << x1 << " is smaller than " << y1 << "." << endl;
    if (x1 <= y1)
        cout << x1 << " is smaller than or equal to " << y1 << "." << endl;

    bigint x2(123456789, 111, 111, 111, 111);
    bigint y2(111111111, 111, 111, 111, 111);

    if (x2 == y2)
        cout << x2 << " is equal to " << y2 << "." << endl;
    if (x2 != y2)
        cout << x2 << " is not equal to " << y2 << "." << endl;
    if (x2 > y2)
        cout << x2 << " is larger than " << y2 << "." << endl;
    if (x2 >= y2)
        cout << x2 << " is larger than or equal to " << y2 << "." << endl;
    if (x2 < y2)
        cout << x2 << " is smaller than " << y2 << "." << endl;
    if (x2 <= y2)
        cout << x2 << " is smaller than or equal to " << y2 << "." << endl;

    bigint x3(123456789, 12, 12);
    bigint y3(111111111, 13, 12);

    if (x3 == y3)
        cout << x3 << " is equal to " << y3 << "." << endl;
    if (x3 != y3)
        cout << x3 << " is not equal to " << y3 << "." << endl;
    if (x3 > y3)
        cout << x3 << " is larger than " << y3 << "." << endl;
    if (x3 >= y3)
        cout << x3 << " is larger than or equal to " << y3 << "." << endl;
    if (x3 < y3)
        cout << x3 << " is smaller than " << y3 << "." << endl;
    if (x3 <= y3)
        cout << x3 << " is smaller than or equal to " << y3 << "." << endl;

    bigint x4(999999999, 999999999, 999999999, 20);

    cout << x4 << "+1 = " << x4 + 1 << endl;

    bigint y4(000000000, 000000000, 000000000, 000000000, 0000000001);

    cout << y4 << "-1 = " << y4 - 1 << endl;

    cout << x1 + x2 + x3 + x4 - y3 + 1 << endl;

    for (int i = 0; i < 3; i++)
    {
        bigint x5, y5;
        cin >> x5 >> y5;
        cout << "x = " << x5 << endl;
        cout << "y = " << y5 << endl;

        cout << "x+y=" << x5 + y5 << endl;
        cout << "x-y=" << x5 - y5 << endl;
    }

    return 0;
}
