package template;

public class Template {

    /**
     * Reverse a int, also can be apply to long, etc...
     */
    public int reverseInt(int input) {
        long reversedNum = 0;
        long input_long = input;

        while (input_long != 0) {
            reversedNum = reversedNum * 10 + input_long % 10;
            input_long = input_long / 10;
        }
        if (reversedNum > Integer.MAX_VALUE || reversedNum < Integer.MIN_VALUE) {
            throw new IllegalStateException();
        }
        return (int) reversedNum;
    }


}
