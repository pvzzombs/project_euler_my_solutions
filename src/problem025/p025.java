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

public class p025 {
  public static void main(String[] args) {
    FibonacciNumber app = new FibonacciNumber();
    System.out.print("The index of the first term in the Fibonacci sequence to contain 1000 digits is ");
    System.out.print(app.run());
    System.out.println(".");
  }
}