/**
 * @author Oliver Krauss on 19.08.2019
 */

public class SqrtJava {

  public static void main(String [] args)
  {
    double input = args.length > 0 && ! args[0].isEmpty() ? Double.valueOf(args[0]) : 1.0;
    double result = Math.sqrt(input);

    System.out.println("Reversed " + result * result);

    System.out.println("Value " + input);

    System.out.println("Jav Bprc " + result + " Bhex " + Double.toHexString(result));

  }

}

