
class Date
{
public:
    int day, month, year;
    int sizedate()
    {
        int m = 6;
        if (day < 10)
            m++;
        else
            m += 2;
        if (month < 10)
            m++;
        else
            m = m + 2;
        return m;
    }
};