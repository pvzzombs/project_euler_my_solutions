import java.math.BigInteger;

class FibonacciNumber {
  public long run() {
    long index = 1;
    BigInteger a, b, temp;
    a = new BigInteger("1");
    b = new BigInteger("1");
    temp = new BigInteger("0");

    while(a.toString().length() < 1000) {
      temp = a.add(b);
      a = b;
      b = temp;
      index++;
    }
    return index;
  }
}