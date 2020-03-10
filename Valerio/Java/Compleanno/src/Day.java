import java.util.Calendar;

public class Day  {
    private int year, month, day;

    Day() {
        year = Calendar.getInstance().get(Calendar.YEAR);
        month = Calendar.getInstance().get(Calendar.MONTH);
        day = Calendar.getInstance().get(Calendar.DATE);
    }

    Day(int year, int month, int day) {
        this.year = year;
        this.month = month - 1;
        this.day = day;
    }

    private int[] daysYear(int year) {
        int[] array = {
                31, 28 + (year % 4 == 0 ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };
        return array;
    }

    private int reduce(int[] array) {
        int count = 0;
        for(int x: array)
            count += x;
        return count;
    }

    public int[] getDate() {
        int[] array = {
                this.year,
                this.month,
                this.day
        };
        return array;
    }

    public int daysFrom(Day date) {
        int days = 0;
        int[] diffs = {
                this.year - date.getDate()[0],
                this.month - date.getDate()[1],
                this.day - date.getDate()[2],
        };

        if (diffs[0] < 0)
            return 0;

        for(int y = date.getDate()[0]; y < this.year; y++)
            days += reduce(daysYear(y));

        for(int m = 0; m < date.getDate()[1]; m++)
            days -= daysYear(date.getDate()[0])[m];

        for(int m = 0; m < this.month; m++)
            days += daysYear(this.year)[m];

        days = days - date.getDate()[2] + this.day;

        return days;
    }

}