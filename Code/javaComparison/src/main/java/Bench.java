import java.time.Duration;
import java.time.Instant;

/**
 * @author Oliver Krauss on 19.08.2019
 */

public class Bench {

  public static void main(String [] args)
  {
    double input = args.length > 0 && ! args[0].isEmpty() ? Double.valueOf(args[0]) : 1.0;
    double result = Math.cbrt(input);

    double totaltime = 0;
    double x = 0;

    for (int j = 0; j < 1000; j++) {
      Instant start = Instant.now();
      for (long i = 0; i < 1000000; i++) {
        x += Math.cbrt(input); // to measure change Math. to the required fn
      }
      Instant finish = Instant.now();
      double timeElapsed = Duration.between(start, finish).toNanos();
      System.out.println("time " + timeElapsed);
      totaltime = timeElapsed + totaltime;
    }
    System.out.println("AVG " + totaltime / 1E9); // as it is nanos we need to divide by repeats and iteratios
    System.out.println("ignore" + x);

    System.out.println("Reversed " + result * result * result);

    System.out.println("Value " + input);

    System.out.println("Jav Bprc " + result + " Bhex " + Double.toHexString(result));

  }

}

