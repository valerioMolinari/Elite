import java.util.Objects;
import java.util.regex.Pattern;

public class Fraction {

    private int numerator;
    private int denominator;

    /**
     * Constructor
     *
     * @param numr
     * @param denr
     */
    public Fraction(int numr, int denr) {
        numerator = numr;
        denominator = denr;
        reduce();
    }

    public Fraction(int numr) {
        numerator = numr;
        denominator = 1;
        reduce();
    }

    public Fraction(String fraction) {
        Pattern pattern = Pattern.compile("/");
        if (Pattern.matches("-?\\d+/\\d+", fraction)) {
            String[] numDen = pattern.split(fraction);
            this.numerator = Integer.parseInt(numDen[0]);
            this.denominator = Integer.parseInt((numDen[1]));
        } else {
            this.numerator = Integer.parseInt(fraction);
            this.denominator = 1;
        }
    }

    public int getNumerator() {
        return numerator;
    }

    public void setNumerator(int numerator) {
        this.numerator = numerator;
    }

    public int getDenominator() {
        return denominator;
    }

    public void setDenominator(int denominator) {
        this.denominator = denominator;
    }

    /**
     * Calculates gcd of two numbers
     *
     * @param numerator
     * @param denominator
     * @return
     */
    public int calculateGCD(int numerator, int denominator) {
        if (numerator % denominator == 0) {
            return denominator;
        }
        return calculateGCD(denominator, numerator % denominator);
    }

    /**
     * Reduce the fraction to lowest form
     */
    void reduce() {
        int gcd = calculateGCD(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    /**
     * Adds two fractions
     *
     * @param fractionTwo
     * @return
     */
    public Fraction add(Fraction fractionTwo) {
        int numer = (numerator * fractionTwo.getDenominator()) +
                (fractionTwo.getNumerator() * denominator);
        int denr = denominator * fractionTwo.getDenominator();
        return new Fraction(numer, denr);
    }

    /**
     * Subtracts two fractions
     *
     * @param fractionTwo
     * @return
     */
    public Fraction subtract(Fraction fractionTwo) {
        int newNumerator = (numerator * fractionTwo.denominator) -
                (fractionTwo.numerator * denominator);
        int newDenominator = denominator * fractionTwo.denominator;
        return new Fraction(newNumerator, newDenominator);
    }

    /**
     * Multiples two functions
     *
     * @param fractionTwo
     * @return
     */
    public Fraction multiply(Fraction fractionTwo) {
        int newNumerator = numerator * fractionTwo.numerator;
        int newDenominator = denominator * fractionTwo.denominator;
        return new Fraction(newNumerator, newDenominator);
    }

    /**
     * Divides two fractions
     *
     * @param fractionTwo
     * @return
     */
    public Fraction divide(Fraction fractionTwo) {
        int newNumerator = numerator * fractionTwo.getDenominator();
        int newDenominator = denominator * fractionTwo.numerator;
        return new Fraction(newNumerator, newDenominator);
    }

    /**
     * Returns string representation of the fraction
     */
    @Override
    public String toString() {
        return denominator == 1 ? String.valueOf(numerator) : numerator + "/" + denominator;
    }

    public boolean equals(int n) {
        Fraction f = new Fraction(n);
        return this.equals(f);
    }

    public boolean equals(Fraction fractionTwo) {
        if (this == fractionTwo)
            return true;
        return numerator == fractionTwo.numerator &&
                denominator == fractionTwo.denominator;
    }

    @Override
    public int hashCode() {
        return Objects.hash(numerator, denominator);
    }

    public void visualizza() {
        System.out.println(this.toString());
    }
}